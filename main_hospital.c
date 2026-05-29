#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Os seus includes (incluindo o atalho para não precisar criar Projeto no Dev-C++)
#include "fila.h"
#include "pilha.h"
#include "matriz.h"
#include "fila.c"
#include "pilha.c"
#include "matriz.c"

int main() {
    // 1. Inicialização das estruturas
    Fila fila_normal;
    iniciar_fila(&fila_normal);

    Pilha pilha_emergencia;
    iniciar_pilha(&pilha_emergencia, 5); // Suporta 5 pacientes urgentes

    // Assumindo que a matriz tem LINHAS e COLUNAS definidas no matriz.h
    int *leitos = (int*) malloc(LINHAS * COLUNAS * sizeof(int));
    inicializar_matriz(leitos);

    int opcao;
    int gerador_id = 100; // Os IDs dos pacientes vão começar no 100, 101, 102...

    // 2. O Menu Interativo
    do {
        printf("\n======= SISTEMA DO HOSPITAL =======\n");
        printf("1. Adicionar paciente comum (Recepcao/Fila)\n");
        printf("2. Adicionar paciente prioritario (Emergencia/Pilha)\n");
        printf("3. Atender proximo (Prioridade primeiro!)\n");
        printf("4. Mostrar ocupacao da matriz de leitos\n");
        printf("5. Sair\n");
        printf("===================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: { 
                // --- ADICIONAR COMUM ---
                Pessoa p_comum;
                p_comum.id = gerador_id++;
                p_comum.prioridade = 0; // 0 = Normal
                
                printf("Digite o nome do paciente comum: ");
                scanf(" %[^\n]", p_comum.nome); // Lê o nome com espaços
                
                enfileirar(&fila_normal, p_comum);
                printf("\n[SUCESSO] Paciente %s aguardando na Recepcao (Fila).\n", p_comum.nome);
                break;
            }
            case 2: { 
                // --- ADICIONAR PRIORITÁRIO ---
                Pessoa p_urgente;
                p_urgente.id = gerador_id++;
                p_urgente.prioridade = 1; // 1 = Urgente
                
                printf("Digite o nome do paciente URGENTE: ");
                scanf(" %[^\n]", p_urgente.nome);
                
                if (empilhar(&pilha_emergencia, p_urgente) == 1) {
                    printf("\n[ALERTA] Paciente %s aguardando na Emergencia (Pilha).\n", p_urgente.nome);
                }
                break;
            }
            case 3: { 
                // --- ATENDER PRÓXIMO ---
                Pessoa *paciente_atendido = NULL;

                // Regra 1: O Médico vai na Pilha de Emergência primeiro
                paciente_atendido = desempilhar(&pilha_emergencia);

                if (paciente_atendido != NULL) {
                    printf("\n>>> ATENDENDO PRIORIDADE (Pilha): %s (ID: %d) <<<\n", paciente_atendido->nome, paciente_atendido->id);
                } 
                else {
                    // Regra 2: Se não tem emergência, o Médico vai na Fila Comum
                    paciente_atendido = front(&fila_normal);
                    
                    if (paciente_atendido != NULL) {
                        printf("\n>>> ATENDENDO NORMAL (Fila): %s (ID: %d) <<<\n", paciente_atendido->nome, paciente_atendido->id);
                        desenfileirar(&fila_normal); // Confirma a saída da fila
                    }
                }

                // Regra 3: Tenta colocar o paciente no Quarto (Matriz)
                if (paciente_atendido != NULL) {
                    int deucerto = alocar_espaco(leitos, paciente_atendido->id);
                    if (deucerto == 1) {
                        printf("[!] Paciente encaminhado para um leito livre.\n");
                    } else {
                        printf("[ERRO] O Hospital esta lotado! Nao ha vagas na matriz.\n");
                    }
                } else {
                    printf("\n[AVISO] Nao ha nenhum paciente aguardando atendimento.\n");
                }
                break;
            }
            case 4: { 
                // --- MOSTRAR MATRIZ ---
                mostrar_matriz(leitos);
                break;
            }
            case 5: { 
                // --- SAIR ---
                printf("\nEncerrando o sistema e liberando memoria...\n");
                break;
            }
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    // 3. Limpeza final
    destruir_pilha(&pilha_emergencia);
    free(leitos);

    return 0;
}