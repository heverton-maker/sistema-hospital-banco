#include <stdio.h>
#include "matriz_banco.h"

// 1. INICIALIZAR: Zera todos os cronometros dos guiches (tudo livre)
void inicializar_matriz_banco(int *matriz) {
    int total_celulas = GUICHES * OPERACOES; // 3x3 = 9 posicoes na rua reta da RAM
    for (int i = 0; i < total_celulas; i++) {
        *(matriz + i) = 0; // Aritmetica de ponteiros: define tempo inicial como 0 (Livre)
    }
}

// 2. MOSTRAR: Desenha o painel de tempos dos caixas no terminal
void mostrar_matriz_banco(int *matriz) {
    printf("\n=== PAINEL DE ATENDIMENTO DO BANCO (Tempo Restante) ===\n");
    printf("           [Saque]   [Deposito] [Pagamento]\n");
    
    for (int g = 0; g < GUICHES; g++) {
        printf("Guiche %d: ", g + 1);
        for (int o = 0; o < OPERACOES; o++) {
            // FORMULA MAGICA: Transforma linha/coluna no indice linear
            int posicao = (g * OPERACOES) + o;
            int tempo = *(matriz + posicao);
            
            if (tempo == 0) {
                printf("[ LIVRE ]   ");
            } else {
                printf("[%d min]    ", tempo);
            }
        }
        printf("\n"); // Quebra a linha pra desenhar o proximo guiche abaixo
    }
    printf("=======================================================\n\n");
}

// 3. ALOCAR CLIENTE: Encontra um guiche vago para a operacao desejada
int alocar_cliente_banco(int *matriz, int coluna_operacao, int tempo_estimado) {
    for (int g = 0; g < GUICHES; g++) {
        // Calcula a posicao exata daquele guiche para aquela operacao especifica
        int posicao = (g * OPERACOES) + coluna_operacao;
        
        // Se a vaga estiver com tempo 0, significa que o guiche esta desocupado
        if (*(matriz + posicao) == 0) {
            *(matriz + posicao) = tempo_estimado; // Define o tempo que a operacao vai durar
            return g + 1; // Retorna o numero do guiche que pegou o cliente (Sucesso)
        }
    }
    return 0; // Retorna 0 se todos os guiches estiverem ocupados para essa operacao
}

// 4. PASSAR TEMPO: Diminui 1 minuto de todos os atendimentos ativos
void passar_tempo_banco(int *matriz) {
    int total_celulas = GUICHES * OPERACOES;
    printf("\n>>> RELOGIO: Passou 1 minuto no banco... <<<\n");
    
    for (int i = 0; i < total_celulas; i++) {
        // Se o cronometro for maior que zero, significa que tem cliente sendo atendido
        if (*(matriz + i) > 0) {
            *(matriz + i) -= 1; // Diminui 1 minuto do atendimento
        }
    }
}