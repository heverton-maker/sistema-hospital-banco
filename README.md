# Sistema de Gerenciamento (Hospital e Banco)

**Temas:**
1. Atendimento Hospitalar (Principal)
2. Fila de Banco (Secundário - aproveita a mesma lógica)

O projeto foi dividido em arquivos separados para que a mesma base lógica funcione nos dois temas, sem precisarmos escrever o código duas vezes.

# Estrutura do Projeto e Divisão de Tarefas

### 1. `fila.c` (Fila Comum - FIFO)
Responsável pelo fluxo normal de atendimento (Pacientes comuns / Fila normal do banco).
*   Implementar a lógica de Fila utilizando alocação dinâmica de memória.
*   Criar as operações obrigatórias: **enqueue** (inserir no final), **dequeue** (remover da frente) e **front** (consultar o primeiro).
*   Utilizar ponteiros para o gerenciamento e encadeamento dos nós.

### 2. `pilha.c` (Prioridades - LIFO)
Responsável pelo fluxo de prioridade (Emergências / Idosos e Gestantes).
*   Implementar a lógica de Pilha utilizando alocação dinâmica de memória.
*   Criar as operações obrigatórias: **push** (empilhar no topo), **pop** (desempilhar do topo) e **top/peek** (consultar o topo).
*   Garantir que o último a chegar seja o primeiro a ser atendido, utilizando ponteiros para os nós.

### 3. `matriz.c` (Gestão de Dados e Espaço)
Responsável pelo armazenamento de informações estáticas e dimensionais.
*   **Array Unidimensional:** Criar e manipular o vetor responsável por armazenar os nomes, IDs ou códigos dos pacientes/clientes que estão aguardando.
*   **Matriz 2D:** Implementar o controle de espaços (Ex: Hospital -> 5 andares × 4 tipos de leito; Banco -> horários × tipos de operação).
*   **Ponteiros:** Implementar obrigatoriamente a lógica de percorrer e consultar a Matriz 2D utilizando aritmética de ponteiros.

### 4. `main_hospital.c` (Interface - Tema 1)
Responsável por integrar as estruturas e interagir com o usuário no contexto do Hospital.
*   Importar as funções de `fila.c`, `pilha.c` e `matriz.c`.
*   Criar o menu interativo no terminal:
    1. Adicionar paciente comum.
    2. Adicionar paciente prioritário.
    3. Atender próximo (com verificação de preferência para a Pilha).
    4. Mostrar ocupação da matriz de leitos.
    5. Sair.
*   Exibir as saídas no terminal (inserções, remoções e consultas).

### 5. `main_banco.c` (Interface - Tema 9)
Responsável por adaptar o sistema para o contexto bancário.
*   Reaproveitar toda a lógica e os menus do `main_hospital.c`.
*   Adaptar as nomenclaturas impressas no terminal (trocar "Pacientes" por "Clientes", "Leitos" por "Tempo por Operação", etc.).