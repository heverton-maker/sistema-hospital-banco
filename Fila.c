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


void desenfileirar(Fila *f) { //  Remover da frente
    if (f->inicio == NULL) {
        printf("A fila ja esta vazia!\n");
        return; // Sai da função para não dar Segmentation Fault
    }  
    No *aux = f->inicio; // Placa clone
    f->inicio = aux->proximo; // A fila anda (placa oficial passa para o segundo da fila)
    free(aux); // Libera a memória 
    if (f->inicio == NULL) {
        f->fim = NULL;  //Se a fila esvaziou, o fim também precisa ser NULL
    }
}


Pessoa* front(Fila *f) { // FRONT: Consultar quem é o primeiro da fila 
    if (f->inicio == NULL) {
        return NULL; // Fila vazia, não há ninguém na frente
    }

    return &(f->inicio->dados); // Retorna o endereço da ficha da primeira pessoa
}



