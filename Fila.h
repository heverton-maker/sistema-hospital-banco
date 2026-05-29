#ifndef FILA_H
#define FILA_H 
// As duas linhas acima evitam que o compilador leia este arquivo duplicado e de erro

// DADOS: A ficha da pessoa (Paciente ou Cliente)
typedef struct {
    int id;           // Numero de identificacao (senha do banco ou registro do hospital)
    char nome[50];    // Nome da pessoa
    int prioridade;   // 0 para Comum, 1 para Prioridade
} Pessoa;

// 2. NÓ: O "Vagao" da nossa fila dinamica
typedef struct no {
    Pessoa dados;       // A ficha da pessoa que esta neste lugar da fila
    struct no *proximo; // O ponteiro (engate) que aponta para a pessoa de tras
} No;

// CONTROLE DA FILA: As placas de sinalizacao
typedef struct {
    No *inicio; // Aponta para o primeiro da fila (quem vai ser atendido)
    No *fim;    // Aponta para o ultimo da fila (onde entram as pessoas novas)
} Fila;

// FUNCOES: As acoes que o sistema pode fazer
void iniciar_fila(Fila *f);                   // Prepara a fila para começar (zera os ponteiros para NULL)
void enfileirar(Fila *f, Pessoa nova_pessoa); // Adiciona uma nova pessoa sempre no FIM da fila
void desenfileirar(Fila *f);                  // Remove sempre a primeira pessoa (INICIO) da fila
Pessoa* front(Fila *f);                       // Apenas "espia" quem e o primeiro, mas nao tira ele da fila
void destruir_fila(Fila *f);

#endif //fecha o #ifndef do topo