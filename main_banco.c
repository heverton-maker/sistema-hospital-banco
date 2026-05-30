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

    Pilha pilha_prioridade;
    iniciar_pilha(&pilha_prioridade, 5); 

    int *caixas = (int*) malloc(NUM_CAIXAS * OPERACOES * sizeof(int));
    inicializar_matriz(caixas);

    int opcao;
    int gerador_senha = 1; 
    
    int historico_ids[100]; 
    int total_clientes_dia = 0;

    // Menu do sistema
    do {
        printf("\n======= CAIXA FINANCEIRO DO HOSPITAL =======\n");
        printf("1. Chegou Paciente Comum (Para Pagamento)\n");
        printf("2. Chegou Paciente Prioridade (Gestante/Idoso)\n");
        printf("3. Atender Proximo Paciente\n");
        printf("4. Passar o Tempo (Avancar 1 minuto)\n");
        printf("5. Mostrar Painel de Caixas\n");
        printf("6. Mostrar Historico de Pacientes\n"); 
        printf("7. Sair\n"); 
        printf("==========================================\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);
        fflush(stdin); // Limpeza de teclado padrao

        switch(opcao) {
            case 1: { 
                // ADICIONAR COMUM 
                Pessoa c_comum;
                c_comum.id = gerador_senha++;
                c_comum.prioridade = 0;
                
                printf("Nome do paciente (Normal): ");
                scanf(" %[^\n]", c_comum.nome); 
                
                enfileirar(&fila_normal, c_comum);
                printf("Paciente %s adicionado a fila normal.\n", c_comum.nome);
                
                historico_ids[total_clientes_dia] = c_comum.id;
                total_clientes_dia++;
                break;
            }
            case 2: { 
                // ADICIONAR PRIORIDADE 
                Pessoa c_prio;
                c_prio.id = gerador_senha++;
                c_prio.prioridade = 1;
                
                printf("Nome do paciente (Idoso/Gestante): ");
                scanf(" %[^\n]", c_prio.nome);
                
                if (empilhar(&pilha_prioridade, c_prio) == 1) {
                    printf("Paciente %s adicionado a pilha de prioridade.\n", c_prio.nome);
                    
                    historico_ids[total_clientes_dia] = c_prio.id;
                    total_clientes_dia++;
                }
                break;
            }
            case 3: { 
                // ATENDER PROXIMO
                Pessoa *cliente_atendido = NULL;
                Pessoa cliente_salvo;
                int atendeu_alguem = 0;

                cliente_atendido = desempilhar(&pilha_prioridade);

                if (cliente_atendido != NULL) {
                    cliente_salvo = *cliente_atendido;
                    atendeu_alguem = 1;
                    printf("Atendendo prioridade: %s (Senha: %d)\n", cliente_salvo.nome, cliente_salvo.id);
                } 
                else {
                    cliente_atendido = front(&fila_normal);
                    if (cliente_atendido != NULL) {
                        cliente_salvo = *cliente_atendido;
                        atendeu_alguem = 1;
                        printf("Atendendo normal: %s (Senha: %d)\n", cliente_salvo.nome, cliente_salvo.id);
                        desenfileirar(&fila_normal); 
                    }
                }

                if (atendeu_alguem == 1) {
                    int op_banco;
                    printf("Operacao desejada? [0] Pagar Consulta | [1] Acerto de Exames | [2] Liberacao de Plano: ");
                    scanf("%d", &op_banco);
                    
                    int tempo = 0;
                    if (op_banco == 0) tempo = 3;
                    else if (op_banco == 1) tempo = 4;
                    else if (op_banco == 2) tempo = 5;
                    else {
                        printf("Operacao invalida.\n");
                        break;
                    }

                    int caixa_livre = alocar_cliente(caixas, op_banco, tempo);
                    
                    if (caixa_livre != 0) {
                        printf("Paciente encaminhado para o Caixa %d.\n", caixa_livre);
                    } else {
                        printf("Erro: Todos os caixas ocupados para esta operacao.\n");
                    }
                } else {
                    printf("Nao ha pacientes aguardando.\n");
                }
                break;
            }
            case 4: { 
                // PASSAR O TEMPO
                passar_tempo(caixas);
                mostrar_matriz(caixas); 
                break;
            }
            case 5: { 
                // MOSTRAR MATRIZ
                mostrar_matriz(caixas);
                break;
            }
            case 6: { 
                // HISTORICO
                printf("\n--- HISTORICO DE PACIENTES ---\n");
                if (total_clientes_dia == 0) {
                    printf("Nenhum paciente ainda.\n");
                } else {
                    printf("Senhas (IDs) registradas: ");
                    for(int i = 0; i < total_clientes_dia; i++) {
                        printf("[%d] ", historico_ids[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 7: { 
                // SAIR
                printf("Encerrando...\n");
                break;
            }
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 7); 

    // Limpeza final
    destruir_pilha(&pilha_prioridade);
    destruir_fila(&fila_normal);
    free(caixas); 

    return 0;
}