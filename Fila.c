#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

//a pagando o lixo de memoria
void iniciar_fila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}


void enfileirar(Fila *f, Pessoa nova_pessoa) { // Inserir no final
    No *novo_no = (No*) malloc(sizeof(No)); // Cria espaço na fila
    if (novo_no == NULL) {
        printf("Erro: Memoria cheia!\n");
        return;
    }
    novo_no->dados = nova_pessoa; // Coloca os dados da pessoa nesse espaço
    novo_no->proximo = NULL; // Fim da fila
   
    if (f->inicio == NULL) { // Fila vazia
        f->inicio = novo_no;
        f->fim = novo_no;
    } else { 
        f->fim->proximo = novo_no;
        f->fim = novo_no;
    }
}






void desenfileirar (Fila *f)
Pessoa* front(Fila *f)