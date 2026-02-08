# Exercício: Phonebook Manager

Criar um programa em C que gerencie uma lista de contatos, permitindo inserir, listar e buscar contatos por nome.

O programa deve usar apenas arrays dinâmicos (`malloc` / `realloc`). Não é permitido usar funções de string avançadas como `strtok` ou `strdup`, sendo permitido apenas `strlen`, `strcpy` e `strcmp`. O código deve compilar sem warnings com o comando:

gcc -Wall -Wextra -Werror phonebook.c -o phonebook

Não são permitidas variáveis globais. Cada contato deve ser definido com a seguinte estrutura:

typedef struct {
    char nome[50];
    char telefone[20];
} Contato;

Ao inserir um contato, o programa deve evitar nomes duplicados. Ao listar os contatos, estes devem aparecer ordenados alfabeticamente pelo nome.

O programa deve apresentar um menu com as seguintes opções:

1 - Inserir contato  
2 - Listar contatos  
3 - Buscar contato por nome  
4 - Sair  

Na opção de inserir, o programa deve solicitar o nome e o telefone e adicionar o contato ao array dinâmico, não permitindo a inserção de nomes duplicados. Na opção de listar, todos os contatos cadastrados devem ser exibidos em ordem alfabética pelo nome. Na opção de buscar, o programa deve solicitar o nome do contato e exibir o telefone caso exista; caso contrário, deve imprimir a mensagem:

Contato nao encontrado.

O código deve estar livre de memory leaks (verificado com Valgrind). O menu e as funcionalidades devem estar separados em funções, não devendo toda a lógica ficar concentrada no `main`. A funcionalidade mínima obrigatória do programa é permitir inserir, listar e buscar contatos.


# Exercício: Task Manager (Lista de Tarefas)

Criar um programa em C que gerencie uma lista de tarefas. O programa deve permitir adicionar, listar, marcar como concluída e remover tarefas.

O programa deve usar apenas arrays dinâmicos (`malloc` / `realloc`). Não são permitidas variáveis globais. Não é permitido usar funções de string avançadas (`strtok`, `strdup`), sendo permitido apenas `strlen`, `strcpy` e `strcmp`.

O código deve compilar sem warnings com o comando:

gcc -Wall -Wextra -Werror taskmanager.c -o taskmanager

Cada tarefa deve ser representada pela seguinte estrutura:

typedef struct {
    char descricao[100];
    int concluida;
} Tarefa;

Ao adicionar uma tarefa, a descrição não pode ser vazia. O campo `concluida` deve iniciar sempre com o valor 0 (não concluída).

O programa deve apresentar um menu com as seguintes opções:

1 - Adicionar tarefa  
2 - Listar tarefas  
3 - Marcar tarefa como concluída  
4 - Remover tarefa  
5 - Sair  

Na opção de adicionar, o programa deve solicitar a descrição da tarefa e adicioná-la ao array dinâmico. Na opção de listar, todas as tarefas devem ser exibidas com o seu estado, indicando `[ ]` para tarefas não concluídas e `[X]` para tarefas concluídas, numeradas a partir de 1.

Na opção de marcar como concluída, o programa deve solicitar o número da tarefa e atualizar o seu estado para concluída. Caso o número seja inválido, o programa deve exibir uma mensagem de erro.

Na opção de remover, o programa deve solicitar o número da tarefa e removê-la do array, reorganizando corretamente a memória.

O código deve estar livre de memory leaks (verificado com Valgrind). O menu e as funcionalidades devem estar separados em funções, não devendo toda a lógica ficar concentrada no `main`. A funcionalidade mínima obrigatória do programa é permitir adicionar, listar, marcar como concluída e remover tarefas.

# Exercício: Inventory Manager (Gestor de Stock)

Criar um programa em C que gerencie um inventário de produtos. O programa deve permitir adicionar produtos, listar o inventário, atualizar a quantidade em stock e remover produtos.

O programa deve usar apenas arrays dinâmicos (`malloc` / `realloc`). Não são permitidas variáveis globais. Não é permitido usar funções de string avançadas (`strtok`, `strdup`), sendo permitido apenas `strlen`, `strcpy` e `strcmp`.

O código deve compilar sem warnings com o comando:

gcc -Wall -Wextra -Werror inventory.c -o inventory

Cada produto deve ser representado pela seguinte estrutura:

typedef struct {
    int id;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

O campo `id` deve ser único e atribuído automaticamente pelo programa (incremental). Não é permitido inserir produtos com nomes duplicados. A quantidade não pode ser negativa e o preço deve ser maior que zero.

O programa deve apresentar um menu com as seguintes opções:

1 - Adicionar produto  
2 - Listar produtos  
3 - Atualizar stock  
4 - Remover produto  
5 - Sair  

Na opção de adicionar, o programa deve solicitar o nome, a quantidade inicial e o preço do produto, validar os dados e adicioná-lo ao array dinâmico.

Na opção de listar, todos os produtos devem ser exibidos mostrando o ID, nome, quantidade e preço.

Na opção de atualizar stock, o programa deve solicitar o ID do produto e a nova quantidade. Caso o ID não exista, deve imprimir:

Produto nao encontrado.

Na opção de remover, o programa deve solicitar o ID do produto e removê-lo do array dinâmico, reorganizando corretamente a memória.

O código deve estar livre de memory leaks (verificado com Valgrind). O menu e as funcionalidades devem estar separados em funções, não devendo toda a lógica ficar concentrada no `main`. A funcionalidade mínima obrigatória do programa é permitir adicionar, listar, atualizar stock e remover produtos.
