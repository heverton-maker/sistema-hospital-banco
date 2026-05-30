#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h" 

// Inicializa a fila
void iniciar_fila(Fila *f) {
    f->inicio = NULL; 
    f->fim = NULL;    
}

// Insere um elemento no final da fila
void enfileirar(Fila *f, Pessoa nova_pessoa) {
    No *novo_no = (No*) malloc(sizeof(No)); 
    
    if (novo_no == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return;
    }
    
    novo_no->dados = nova_pessoa; 
    novo_no->proximo = NULL;      
    
    // Verifica se a fila esta vazia
    if (f->inicio == NULL) { 
        f->inicio = novo_no;
        f->fim = novo_no;
    } else { 
        // Insere no final e atualiza o ponteiro
        f->fim->proximo = novo_no;
        f->fim = novo_no;
    }
}

// Remove o elemento do inicio da fila
void desenfileirar(Fila *f) { 
    if (f->inicio == NULL) {
        printf("Fila vazia.\n");
        return; 
    }  
    
    No *aux = f->inicio; 
    
    f->inicio = aux->proximo; 
    
    free(aux); 
    
    // Se a fila esvaziou, atualiza o fim para NULL
    if (f->inicio == NULL) {
        f->fim = NULL;  
    }
}

// Retorna os dados do primeiro elemento sem remove-lo
Pessoa* front(Fila *f) { 
    if (f->inicio == NULL) {
        return NULL; 
    }

    return &(f->inicio->dados); 
}

// Libera toda a memoria alocada para a fila
void destruir_fila(Fila *f) {
    No *atual = f->inicio; 
    No *proximo_no;

    while (atual != NULL) {
        proximo_no = atual->proximo; 
        free(atual);                 
        atual = proximo_no;          
    }
    
    f->inicio = NULL;
    f->fim = NULL;
}
