#include <stdio.h>
#include "matriz.h"

// Inicializa a matriz
void inicializar_matriz(int *matriz) {
    int total_celulas = NUM_CAIXAS * OPERACOES; 
    
    for (int i = 0; i < total_celulas; i++) {
        matriz[i] = 0; 
    }
}

// Imprime o estado atual dos caixas
void mostrar_matriz(int *matriz) {
    printf("\nEstado dos Caixas (Tempo Restante):\n");
    printf("          [Consulta] [Exames] [Plano]\n");
    
    for (int l = 0; l < NUM_CAIXAS; l++) {
        printf("Caixa %d:  ", l + 1);
        for (int c = 0; c < OPERACOES; c++) {
            
            int posicao = (l * OPERACOES) + c;
            int tempo = matriz[posicao]; 
            
            if (tempo == 0) {
                printf("[ LIVRE ]  ");
            } else {
                printf("[%d min]   ", tempo);
            }
        }
        printf("\n"); 
    }
    printf("\n");
}

// Procura caixa livre para a operacao
int alocar_cliente(int *matriz, int coluna_operacao, int tempo_estimado) {
    for (int l = 0; l < NUM_CAIXAS; l++) {
        
        int posicao = (l * OPERACOES) + coluna_operacao;
        
        if (matriz[posicao] == 0) {
            matriz[posicao] = tempo_estimado; 
            return l + 1; 
        }
    }
    
    return 0; 
}

// Atualiza o tempo dos atendimentos em andamento
void passar_tempo(int *matriz) {
    int total_celulas = NUM_CAIXAS * OPERACOES;
    printf("Avancando tempo em 1 minuto...\n");
    
    for (int i = 0; i < total_celulas; i++) {
        if (matriz[i] > 0) {
            matriz[i] -= 1; 
        }
    }
}