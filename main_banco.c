#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- ATALHO DE COMPILACAO ---
#include "fila.h"
#include "pilha.h"
#include "matriz_banco.h"
#include "fila.c"
#include "pilha.c"
#include "matriz_banco.c"

int main() {
    // 1. INICIAR ESTRUTURAS
    Fila fila_normal;
    iniciar_fila(&fila_normal);

    Pilha pilha_prioridade;
    iniciar_pilha(&pilha_prioridade, 5); 

    int *caixas = (int*) malloc(GUICHES * OPERACOES * sizeof(int));
    inicializar_matriz_banco(caixas);

    int opcao;
    int gerador_senha = 1; 

    // ---> AQUI ESTÁ O ARRAY UNIDIMENSIONAL EXIGIDO PELO PROFESSOR <---
    int historico_ids[100]; 
    int total_clientes_dia = 0;

    // 2. MENU INTERATIVO DO BANCO
    do {
        printf("\n======= SISTEMA DO BANCO =======\n");
        printf("1. Chegou Cliente Comum )\n");
        printf("2. Chegou Prioridade Legal \n");
        printf("3. Atender Proximo Cliente\n");
        printf("4. Passar o Tempo (Avancar 1 minuto)\n");
        printf("5. Mostrar Painel de Guiches\n");
        printf("6. Mostrar Historico de IDs (Array 1D)\n"); // <--- Opcao nova no menu!
        printf("7. Sair\n"); // <--- Sair mudou para o 7
        printf("=================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: { 
                // --- CLIENTE NORMAL ---
                Pessoa c_comum;
                c_comum.id = gerador_senha++;
                c_comum.prioridade = 0;
                
                printf("Nome do cliente (Normal): ");
                scanf(" %[^\n]", c_comum.nome); 
                
                enfileirar(&fila_normal, c_comum);
                printf("\n[SUCESSO] Cliente %s (Senha %d) aguardando na Fila.\n", c_comum.nome, c_comum.id);
                
                // Salva o ID no nosso Array Unidimensional
                historico_ids[total_clientes_dia] = c_comum.id;
                total_clientes_dia++;
                break;
            }
            case 2: { 
                // --- CLIENTE PRIORIDADE ---
                Pessoa c_prio;
                c_prio.id = gerador_senha++;
                c_prio.prioridade = 1;
                
                printf("Nome do cliente (Idoso/Gestante): ");
                scanf(" %[^\n]", c_prio.nome);
                
                if (empilhar(&pilha_prioridade, c_prio) == 1) {
                    printf("\n[ALERTA] Cliente %s (Senha %d) aguardando na Pilha de Prioridade.\n", c_prio.nome, c_prio.id);
                    
                    // Salva o ID no nosso Array Unidimensional
                    historico_ids[total_clientes_dia] = c_prio.id;
                    total_clientes_dia++;
                }
                break;
            }
            case 3: { 
                // --- ATENDER PRÓXIMO ---
                Pessoa *cliente_atendido = NULL;

                cliente_atendido = desempilhar(&pilha_prioridade);

                if (cliente_atendido != NULL) {
                    printf("\n>>> ATENDENDO PRIORIDADE: %s (Senha: %d) <<<\n", cliente_atendido->nome, cliente_atendido->id);
                } 
                else {
                    cliente_atendido = front(&fila_normal);
                    if (cliente_atendido != NULL) {
                        printf("\n>>> ATENDENDO NORMAL: %s (Senha: %d) <<<\n", cliente_atendido->nome, cliente_atendido->id);
                        desenfileirar(&fila_normal); 
                    }
                }

                if (cliente_atendido != NULL) {
                    int op_banco;
                    printf("Qual a operacao desejada?\n[0] Saque (3 min) | [1] Deposito (4 min) | [2] Pagamento (5 min): ");
                    scanf("%d", &op_banco);
                    
                    int tempo = 0;
                    if (op_banco == 0) tempo = 3;
                    else if (op_banco == 1) tempo = 4;
                    else if (op_banco == 2) tempo = 5;
                    else {
                        printf("Operacao invalida. Cliente dispensado.\n");
                        break;
                    }

                    int guiche_livre = alocar_cliente_banco(caixas, op_banco, tempo);
                    
                    if (guiche_livre != 0) {
                        printf("[!] Cliente %s encaminhado para o Guiche %d.\n", cliente_atendido->nome, guiche_livre);
                    } else {
                        printf("[ERRO] Todos os guiches para esta operacao estao OCUPADOS! Avance o tempo.\n");
                    }
                } else {
                    printf("\n[AVISO] Nao ha clientes aguardando.\n");
                }
                break;
            }
            case 4: { 
                // --- PASSAR O TEMPO ---
                passar_tempo_banco(caixas);
                mostrar_matriz_banco(caixas); 
                break;
            }
            case 5: { 
                // --- MOSTRAR MATRIZ ---
                mostrar_matriz_banco(caixas);
                break;
            }
            case 6: { 
                // ---> NOVO: MOSTRAR O ARRAY UNIDIMENSIONAL <---
                printf("\n--- HISTORICO DE IDs GERADOS NO DIA ---\n");
                if (total_clientes_dia == 0) {
                    printf("Nenhum cliente entrou no banco ainda.\n");
                } else {
                    printf("IDs registrados no Array Unidimensional: ");
                    for(int i = 0; i < total_clientes_dia; i++) {
                        printf("[%d] ", historico_ids[i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 7: { 
                // --- SAIR ---
                printf("\nFechando a agencia e limpando memoria...\n");
                break;
            }
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 7); // <--- O laco agora roda ate digitar 7

    // 3. FAXINA FINAL
    destruir_pilha(&pilha_prioridade);
    free(caixas); 

    return 0;
}