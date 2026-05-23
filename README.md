# Sistema de Gerenciamento (Hospital e Banco)

**Temas:**
1. Atendimento Hospitalar (Principal)
2. Fila de Banco (Secundário - aproveita a mesma lógica)

## Divisão de Arquivos e Tarefas


*   **fila.c (Fila Comum - FIFO):** Funções genéricas para adicionar (enqueue) e remover (dequeue). O código deve usar termos neutros (ex: `novo_no`) para servir nos dois temas.

*   **pilha.c (Prioridades - LIFO):** Funções genéricas para empilhar (push) e desempilhar (pop) emergências ou idosos. Também será reaproveitado nos dois temas.

*   **matriz.c (Mapa e Histórico):** Controla a Matriz 2D (leitos/caixas) usando ponteiros e o Array 1D que guarda o histórico de quem já foi atendido.

*   **main_hospital.c (Interface):** Junta as lógicas acima. Cria o menu no terminal (1. Chegada, 2. Emergência, 3. Atender, 4. Mapa).

*   **main_banco.c (O Clone):** Fica para o final. Será uma cópia exata do `main_hospital.c`, apenas trocando os textos impressos (ex: "Paciente" vira "Cliente").