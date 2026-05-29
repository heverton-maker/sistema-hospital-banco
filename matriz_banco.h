#ifndef MATRIZ_BANCO_H
#define MATRIZ_BANCO_H
// Trava de seguranca para o compilador nao duplicar o arquivo

#define GUICHES 3    // Quantidade de caixas/guiches de atendimento (Linhas)
#define OPERACOES 3  // Tipos de servico: 0 = Saque, 1 = Deposito, 2 = Pagamento (Colunas)

void inicializar_matriz_banco(int *matriz);
void mostrar_matriz_banco(int *matriz);
int alocar_cliente_banco(int *matriz, int coluna_operacao, int tempo_estimado);
void passar_tempo_banco(int *matriz);

#endif // Fim da trava de seguranca