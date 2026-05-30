#ifndef PILHA_H
#define PILHA_H

#include "fila.h" // Necessario para utilizar a struct Pessoa

// Estrutura de controle da pilha 
typedef struct {
    Pessoa *itens;  
    int capacidade; 
    int topo;       
} Pilha;

//  funcoes
void iniciar_pilha(Pilha *p, int capacidade_inicial); // Inicializa a pilha 
int empilhar(Pilha *p, Pessoa nova_pessoa);           // Insere um elemento no topo da pilha
Pessoa* desempilhar(Pilha *p);                        // Remove e retorna o elemento do topo da pilha
void destruir_pilha(Pilha *p);                        // Libera a memoria  do array da pilha

#endif