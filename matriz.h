#ifndef MATRIZ_H
#define MATRIZ_H
// Trava de seguranca para nao ler o arquivo duas vezes

// 1. TAMANHO DO HOSPITAL (Fácil de mudar se o professor pedir mais vagas)
#define LINHAS 3   // Quantidade de Andares
#define COLUNAS 3  // Quantidade de Quartos por Andar

// 2. FUNCOES DA MATRIZ (Aritmetica de Ponteiros)
void inicializar_matriz(int *matriz);          // Prepara o hospital: coloca 0 em todas as vagas (0 = Livre)
void mostrar_matriz(int *matriz);              // Imprime o hospital na tela quebrando as linhas para parecer um predio 2D
int alocar_espaco(int *matriz, int id_pessoa); // Procura o primeiro '0' que encontrar e guarda o ID do paciente nele

#endif // Fecha a trava de seguranca