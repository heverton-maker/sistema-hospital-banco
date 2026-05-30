#ifndef FILA_H
#define FILA_H 

// Estrutura base de dados
typedef struct {
    int id;           // Numero de identificacao
    char nome[50];    // Nome do cliente/paciente
    int prioridade;   // 0 para comum, 1 para prioridade
} Pessoa;

// No da fila dinamica
typedef struct no {
    Pessoa dados;       // Informacoes da pessoa
    struct no *proximo; // Ponteiro para o proximo elemento
} No;

// Estrutura de controle da fila
typedef struct {
    No *inicio; // Aponta para o primeiro elemento (inicio)
    No *fim;    // Aponta para o ultimo elemento (fim)
} Fila;

// Assinaturas das funcoes
void iniciar_fila(Fila *f);                   // Inicializa a fila definindo ponteiros como NULL
void enfileirar(Fila *f, Pessoa nova_pessoa); // Aloca e insere um novo no final da fila
void desenfileirar(Fila *f);                  // Remove e libera a memoria do primeiro no da fila
Pessoa* front(Fila *f);                       // Retorna os dados do primeiro elemento sem remove-lo
void destruir_fila(Fila *f);                  // Percorre a fila liberando toda a memoria alocada

#endif