#ifndef PILHA_H
#define PILHA_H
// As duas linhas acima evitam que o compilador leia este arquivo duplicado e de erro
#include "fila.h" // Importa a struct Pessoa (A ficha) que criamos no outro arquivo

// ESTRUTURA DA PILHA (A sala de Emergencia / LIFO)
typedef struct {
    Pessoa *itens;     // Array dinamico criado com malloc (nosso "tubo")
    int capacidade; // Tamanho maximo da pilha (serve para testar o Overflow)
    int topo; // Marca o indice do ultimo elemento a entrar (comeca em -1)
} Pilha;

// FUNCOES (As acoes da Pilha) 
void iniciar_pilha(Pilha *p, int capacidade_inicial); // Faz o malloc do array e poe o topo em -1
int empilhar(Pilha *p, Pessoa nova_pessoa); // Coloca paciente no TOPO (Faz o topo++)
Pessoa* desempilhar(Pilha *p);// Remove e retorna o paciente do TOPO (Faz o topo--)
void destruir_pilha(Pilha *p); // Da o free() no array para devolver a memoria RAM

#endif // Fecha a protecao do #ifndef la de cima



