#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    char descricao[100];
    int concluida;
} Tarefa;

int menu(int op)
{
    printf("1 - Adicionar tarefa\n"
           "2 - Listar tarefas\n"
           "3 - Marcar tarefa como concluída\n"
           "4 - Remover tarefa\n"
           "5 - Sair\n");
    scanf("%d", &op);
    return op;
}
void adiciona_tarefa(Tarefa **tarefa, int *id)
{

    Tarefa add;
    printf("Adicione uma tarefa\n");
    scanf(" %99[^\n]", add.descricao);
    add.concluida = 0;

    // criando uma compia  da Tarefa *temp
    Tarefa *temp = realloc(*tarefa, (*id + 1) * sizeof(Tarefa));
    if (temp == NULL)
    {
        printf("Erro na memoria");
        return;
    }
    // Passando a copia da memoria para a *tarefa onde esta realocando a memoriapara incrementar um novo espaco na memoria
    *tarefa = temp;
    (*tarefa)[*id] = add;
    (*id)++;
}
void listar_tarefas(Tarefa *tarefas, int id)
{

    for (int i = 0; i < id; i++)
    {
        if (tarefas[i].concluida == 0)
        {
            printf("%d - [ ] %s\n", i + 1, tarefas[i].descricao);
        }
        else
            printf("%d - [X] %s\n", i + 1, tarefas[i].descricao);
    }
}
void tarefa_concluida(Tarefa *tarefas, int id)
{
    int x;
    listar_tarefas(tarefas, id);

    printf("Escolha uma opcao para atualizar como concluido");
    scanf("%d", &x);
    for (int i = 0; i < id; i++)
    {
        if (i == x - 1)
        {

            tarefas[i].concluida = 1;
        }
    }
}

void remover_tarefa(Tarefa **tarefa, int *id)
{
    int x, cont = 0;
    printf("Qual tarefa deseja excluir");
    scanf("%d", &x);
    if (x < 1 || x > *id)
    {
        printf("Tarefa invalida\n");
        return;
    }

    for (int i = 0; i < *id; i++)
    {
        if (i != x - 1)
        {
            (*tarefa)[cont] = (*tarefa)[i];
            cont++;
        }
    }

    *id = cont;
    if (*id > 0)
    {
        Tarefa *temp = realloc(*tarefa, (*id) * sizeof(Tarefa));
        if (temp != NULL)
        {
            *tarefa = temp;
        }
    }
    else
    {
        // Se não houver funcionários, libera a memória
        free(*tarefa);
        *tarefa = NULL;
    }
}
int main()
{
    Tarefa *tarefa = NULL;
    int op = 0, id = 0;
    do
    {
        op = menu(op);
        switch (op)
        {
        case 1:
            adiciona_tarefa(&tarefa, &id);
            break;
        case 2:
            listar_tarefas(tarefa, id);
            break;
        case 3:
            tarefa_concluida(tarefa, id);
            break;
        case 4:
            remover_tarefa(&tarefa, &id);
            break;
        }
    } while (op != 5);
    free(tarefa);
    return 0;
}