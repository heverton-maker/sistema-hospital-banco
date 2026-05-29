#include <stdio.h>
#include "matriz.h"

// INICIALIZAR: Zera o hospital inteiro (prepara os quartos)
void inicializar_matriz(int *matriz) {
    int total_vagas = LINHAS * COLUNAS; // Calcula o total de vagas (Ex: 3x3 = 9)
    
    // Anda pela "rua" reta da memoria RAM
    for (int i = 0; i < total_vagas; i++) {
        *(matriz + i) = 0; // Aritmetica de ponteiros: coloca 0 (Vazio) na posicao atual
    }
}

// MOSTRAR: O truque de fingir que a memoria reta e um predio 2D
void mostrar_matriz(int *matriz) {
    printf("\n=== PAINEL DE LEITOS (0 = Livre) ===\n");
    
    // Loop dos Andares (Linhas)
    for (int l = 0; l < LINHAS; l++) {
        printf("Andar %d: ", l + 1);
        
        // Loop dos Quartos (Colunas)
        for (int c = 0; c < COLUNAS; c++) {
            
            // A FORMULA MAGICA: Transforma a coordenada (linha, coluna) no indice real do array 1D
            int posicao = (l * COLUNAS) + c; 
            
            // Pega o valor que esta exatamente nessa posicao da memoria
            int id_paciente = *(matriz + posicao); 
            
            if (id_paciente == 0) {
                printf("[ VAGO ] ");
            } else {
                printf("[ID:%03d] ", id_paciente);
            }
        }
        printf("\n"); // O "Enter" que quebra a linha e cria a ilusao visual do predio
    }
    printf("====================================\n\n");
}

// ALOCAR ESPACO: Acha o primeiro quarto vazio e interna o paciente
int alocar_espaco(int *matriz, int id_pessoa) {
    int total_vagas = LINHAS * COLUNAS;
    
    // Varre o hospital do primeiro ao ultimo quarto
    for (int i = 0; i < total_vagas; i++) {
        
        // Se olhar para o espaco na memoria e o valor for 0 (Vago)
        if (*(matriz + i) == 0) { 
            
            *(matriz + i) = id_pessoa; // Substitui o 0 pelo ID do paciente
            return 1; // Retorna 1 (Sucesso) para o main e encerra a busca
        }
    }
    
    // Se o loop terminou e nao retornou 1, significa que nao encontrou nenhum zero
    printf("HOSPITAL LOTADO! Nao ha vagas para o ID %d.\n", id_pessoa);
    return 0; // Retorna 0 (Falha) para o main
}