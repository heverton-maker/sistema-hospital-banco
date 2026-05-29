#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// INICIAR: Constrói a pilha vazia na memória
void iniciar_pilha(Pilha *p, int capacidade_inicial) {
    p->capacidade = capacidade_inicial;
    p->topo = -1; // -1 significa "Pilha Vazia" (pois a posição 0 já seria o primeiro paciente)
    
    // Pede memória RAM ao computador para criar o array do tamanho exato que precisamos
    p->itens = (Pessoa*) malloc(capacidade_inicial * sizeof(Pessoa));
    
    if (p->itens == NULL) {
        printf("Erro ao alocar memoria para a Pilha!\n");
        exit(1); // Aborta se o computador não tiver RAM disponível
    }
}

// EMPILHAR: Coloca um paciente no topo da pilha (PUSH)
int empilhar(Pilha *p, Pessoa nova_pessoa) {
    // OVERFLOW: Verifica se o "tubo" já encheu até à borda
    if (p->topo == p->capacidade - 1) {
        printf("Pilha de Emergencia CHEIA!\n");
        return 0; // Falso (Falhou ao empilhar)
    }
    
    p->topo++; // Sobe o marcador (post-it) um andar para cima
    p->itens[p->topo] = nova_pessoa; // Coloca a ficha do paciente nesse novo andar
    
    return 1; // Verdadeiro (Sucesso)
}

// DESEMPILHAR: Tira o paciente que está no topo (POP)
Pessoa* desempilhar(Pilha *p) {
    // UNDERFLOW: Verifica se a pilha já está vazia antes de tentar tirar
    if (p->topo == -1) {
        return NULL; 
    }
    
    // Pega o endereço de memória do paciente que está exatamente na posição do topo
    Pessoa *paciente = &(p->itens[p->topo]);
    
    p->topo--; // A MÁGICA: Apenas descemos o marcador. O sistema "esquece" quem ficou lá em cima.
    
    return paciente; // Entrega o paciente ao Médico
}

//  DESTRUIR: Limpa a sujeira quando o hospital fecha
void destruir_pilha(Pilha *p) {
    free(p->itens);  // Devolve a memória RAM alocada pelo malloc (Evita Memory Leak!)
    p->itens = NULL; // Por segurança, aponta para o nada
}





