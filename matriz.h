#ifndef MATRIZ_H
#define MATRIZ_H

// Dimensoes da matriz do caixa financeiro
#define NUM_CAIXAS 3 // Quantidade de caixas (linhas)
#define OPERACOES 3  // Quantidade de operacoes (colunas)

// Funcoes
void inicializar_matriz(int *matriz);
void mostrar_matriz(int *matriz);
int alocar_cliente(int *matriz, int coluna_operacao, int tempo_estimado);
void passar_tempo(int *matriz);

#endif