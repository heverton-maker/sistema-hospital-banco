#ifndef FILA_H
#define FILA_H 

// O MOLDE DOS DADOS Serve para Hospital e o Banco
typedef struct {
	int id; //senha do banco ou registro do hospital
	char nome[50];
	int prioridade;
}Pessoa;

typedef struct no {
	Pessoa dados;
	struct no *proximo;
}No;

typedef struct{
	No *inicio;
	No *fim;
}Fila;


void iniciar_fila(Fila *f);
void enfileirar (Fila *f, Pessoa nova_pessoa);
void desenfileirar (Fila *f);
Pessoa* front(Fila *f);

#endif