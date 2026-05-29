#include <stdio.h> // Para usar o printf() e scanf() (Entrada e Saida na tela)
#include <stdlib.h> // Para usar o malloc() e free() (Alocacao Dinamica de Memoria)
#include <string.h> // Para lidar com textos e nomes (ex: ler o nome do paciente com espacos)
#include "fila.h" // Para o sistema conhecer a Fila e a struct Pessoa

// INICIAR: Prepara a fila do zero
void iniciar_fila(Fila *f) {
    f->inicio = NULL; // Ninguem no comeco
    f->fim = NULL;    // Ninguem no final
}

// ENFILEIRAR: Adiciona uma pessoa no final da fila
void enfileirar(Fila *f, Pessoa nova_pessoa) {
    // Pede memoria ao computador para criar um novo "vagao"
    No *novo_no = (No*) malloc(sizeof(No)); 
    
    if (novo_no == NULL) {
        printf("Erro: Memoria cheia!\n");
        return;
    }
    
    novo_no->dados = nova_pessoa; // Coloca a ficha da pessoa no vagao
    novo_no->proximo = NULL;      // Como ele e o ultimo, nao tem ninguem atras dele
    
    // Regra principal: Se a fila estiver vazia, ele e o primeiro e o ultimo
    if (f->inicio == NULL) { 
        f->inicio = novo_no;
        f->fim = novo_no;
    } else { 
        // Se ja tem gente, o atual ultimo aponta para ele, e ele vira o novo ultimo
        f->fim->proximo = novo_no;
        f->fim = novo_no;
    }
}

// DESENFILEIRAR: Remove sempre o primeiro da fila (quem foi atendido)
void desenfileirar(Fila *f) { 
    if (f->inicio == NULL) {
        printf("A fila ja esta vazia!\n");
        return; // Sai da funcao para o programa nao quebrar
    }  
    
    No *aux = f->inicio; // Cria um clone apontando para o primeiro (para podermos apagar depois)
    
    f->inicio = aux->proximo; // A fila anda: o segundo passa a ser o oficial primeiro
    
    free(aux); // Libera a memoria do cara que foi atendido (Evita vazamento!)
    
    // Se tiramos o unico que estava la, a fila zerou. O fim tambem vira NULL.
    if (f->inicio == NULL) {
        f->fim = NULL;  
    }
}

// FRONT: Apenas olha quem e o primeiro (Sem tirar da fila)
Pessoa* front(Fila *f) { 
    if (f->inicio == NULL) {
        return NULL; // Fila vazia, nao ha ninguem para olhar
    }

    // Retorna o endereco da ficha do primeiro cara, para o Medico/Gerente ler os dados
    return &(f->inicio->dados); 
}


// DESTRUIR: Limpa a fila inteira caso sobre alguem quando o programa fechar
void destruir_fila(Fila *f) {
    No *atual = f->inicio; // Começa olhando para o primeiro da fila
    No *proximo_no;

    // Enquanto houver pessoas na fila...
    while (atual != NULL) {
        proximo_no = atual->proximo; // Salva quem é o próximo antes de apagar o atual
        free(atual);                 // Libera a memória do vagão atual (Evita o memory leak!)
        atual = proximo_no;          // Anda para o próximo vagão
    }
    
    // Zera os ponteiros por segurança
    f->inicio = NULL;
    f->fim = NULL;
}
