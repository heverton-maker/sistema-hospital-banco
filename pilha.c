#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Inicializa a pilha com a capacidade desejada
void iniciar_pilha(Pilha *p, int capacidade_inicial) {
    p->capacidade = capacidade_inicial;
    p->topo = -1; // -1 indica pilha vazia
    
    p->itens = (Pessoa*) malloc(capacidade_inicial * sizeof(Pessoa));
    
    if (p->itens == NULL) {
        printf("Erro de alocacao de memoria.\n");
        exit(1); 
    }
}

// Insere um elemento no topo da pilha
int empilhar(Pilha *p, Pessoa nova_pessoa) {
    // Verifica se a pilha esta cheia (Overflow)
    if (p->topo == p->capacidade - 1) {
        printf("Erro: Pilha cheia.\n");
        return 0; 
    }
    
    p->topo++; 
    p->itens[p->topo] = nova_pessoa; 
    
    return 1; 
}

// Remove e retorna o elemento do topo da pilha
Pessoa* desempilhar(Pilha *p) {
    // Verifica se a pilha esta vazia (Underflow)
    if (p->topo == -1) {
        return NULL; 
    }
    
    Pessoa *paciente = &(p->itens[p->topo]);
    
    p->topo--; 
    
    return paciente; 
}

// Libera a memoria alocada para o array da pilha
void destruir_pilha(Pilha *p) {
    free(p->itens);  
    p->itens = NULL; 
}