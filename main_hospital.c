#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fila.h"
#include "pilha.h"
#include "matriz.h"
#include "fila.c"
#include "pilha.c"
#include "matriz.c"

int main() {
    // Inicializacao das estruturas
    Fila fila_normal;
    iniciar_fila(&fila_normal);

    Pilha pilha_emergencia;
    iniciar_pilha(&pilha_emergencia, 5); 

    int *leitos = (int*) malloc(LINHAS * COLUNAS * sizeof(int));
    inicializar_matriz(leitos);

    int opcao;
    int gerador_id = 100; 

    // Menu do sistema
    do {
        printf("\n======= SISTEMA DO HOSPITAL =======\n");
        printf("1. Adicionar paciente comum \n");
        printf("2. Adicionar paciente prioritario \n");
        printf("3. Atender proximo\n");
        printf("4. Mostrar ocupacao da matriz de leitos\n");
        printf("5. Sair\n");
        printf("===================================\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);
        fflush(stdin); // Limpa o buffer do teclado (versao estudante)

        switch(opcao) {
            case 1: { 
                // ADICIONAR COMUM
                Pessoa p_comum;
                p_comum.id = gerador_id++;
                p_comum.prioridade = 0; 
                
                printf("Digite o nome do paciente comum: ");
                scanf(" %[^\n]", p_comum.nome); 
                
                enfileirar(&fila_normal, p_comum);
                printf("Paciente %s adicionado a fila normal.\n", p_comum.nome);
                break;
            }
            case 2: { 
                // ADICIONAR PRIORITARIO
                Pessoa p_urgente;
                p_urgente.id = gerador_id++;
                p_urgente.prioridade = 1; 
                
                printf("Digite o nome do paciente URGENTE: ");
                scanf(" %[^\n]", p_urgente.nome); 
                
                if (empilhar(&pilha_emergencia, p_urgente) == 1) {
                    printf("Paciente %s adicionado a pilha de emergencia.\n", p_urgente.nome);
                }
                break;
            }
            case 3: { 
                // ATENDER PROXIMO
                Pessoa *paciente_atendido = NULL;
                Pessoa paciente_salvo;
                int atendeu_alguem = 0;

                // Regra 1: O Medico vai na Pilha de Emergencia primeiro
                paciente_atendido = desempilhar(&pilha_emergencia);

                if (paciente_atendido != NULL) {
                    paciente_salvo = *paciente_atendido; 
                    atendeu_alguem = 1;
                    printf("Atendendo emergencia: %s (ID: %d)\n", paciente_salvo.nome, paciente_salvo.id);
                } 
                else {
                    // Regra 2: Se nao tem emergencia, o Medico vai na Fila Comum
                    paciente_atendido = front(&fila_normal);
                    
                    if (paciente_atendido != NULL) {
                        paciente_salvo = *paciente_atendido; 
                        atendeu_alguem = 1;
                        printf("Atendendo normal: %s (ID: %d)\n", paciente_salvo.nome, paciente_salvo.id);
                        desenfileirar(&fila_normal); 
                    }
                }

                // Regra 3: Tenta colocar o paciente no Quarto (Matriz)
                if (atendeu_alguem == 1) {
                    int deucerto = alocar_espaco(leitos, paciente_salvo.id);
                    if (deucerto == 1) {
                        printf("Paciente encaminhado para leito.\n");
                    } else {
                        printf("Erro: Hospital lotado.\n");
                    }
                } else {
                    printf("Nao ha pacientes aguardando.\n");
                }
                break;
            }
            case 4: { 
                // MOSTRAR MATRIZ
                mostrar_matriz(leitos);
                break;
            }
            case 5: { 
                // SAIR
                printf("Encerrando...\n");
                break;
            }
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 5);

    // Limpeza final
    destruir_pilha(&pilha_emergencia);
    destruir_fila(&fila_normal);
    free(leitos);

    return 0;
}