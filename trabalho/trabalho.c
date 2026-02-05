#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_TEXTO 60


typedef struct
{
    int id;
    char nome[MAX_TEXTO];
    char apelido[MAX_TEXTO];
    int idade;
    char funcao[MAX_TEXTO];
    char dataNascimento[11]; // "DD/MM/AAAA" -> 10 + '\0'
    double salario;          // campo extra escolhido
} Funcionario;

void inserirFuncionario(Funcionario **vetor, int *idCont, int *ultimoId)
{
    Funcionario *temp =realloc(*vetor,(*idCont+1)*sizeof(Funcionario));
    if (temp == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    *vetor = temp;

    Funcionario funcionario;
    funcionario.id = (*ultimoId)++;
    printf("nome:");
    scanf(" %[^\n]", funcionario.nome);

    (*vetor)[*idCont] = funcionario;
    (*idCont)++;
}
void listarFuncionarios(Funcionario *vetor, int *idCont, int op, int *ultimoId)
{
    if (op == 4)
    {

        for (int i = 0; i < *idCont; i++)
        {
            printf("ID: %d, Nome: %s\n", vetor[i].id, vetor[i].nome);
        }
    }
    else
    {
        int cont = 0;
        Funcionario vetorOrdenadoId[*idCont];
        for (int i = *ultimoId; i >= 0; i--)
        {
            for (int j = 0; j < *idCont; j++)
            {
                if (vetor[j].id == i)
                {
                    vetorOrdenadoId[cont] = vetor[j];
                    cont++;
                }
            }
        }
        for (int i = 0; i < cont; i++)
        {
            printf("ID: %d, Nome: %s\n", vetorOrdenadoId[i].id, vetorOrdenadoId[i].nome);
        }
    }
}
void listarFuncionariosPorNome(Funcionario *vetor, int *idCont)
{
    Funcionario vetorOrdenado[*idCont];

    for (int i = 0; i < *idCont; i++)
    {
        vetorOrdenado[i] = vetor[i];
    }

    for (int i = 0; i < *idCont - 1; i++)
    {
        for (int j = i + 1; j < *idCont; j++)
        {
            if (strcmp(vetorOrdenado[i].nome, vetorOrdenado[j].nome) > 0)
            {
                Funcionario temp = vetorOrdenado[i];
                vetorOrdenado[i] = vetorOrdenado[j];
                vetorOrdenado[j] = temp;
            }
        }
    }

    for (int i = 0; i < *idCont; i++)
    {
        printf("ID: %d, Nome: %s\n",
               vetorOrdenado[i].id,
               vetorOrdenado[i].nome);
    }
}

void apagarFuncionario(Funcionario **vetor, int *idCont)
{
    int id = 0, cont = 0, encontrado = 0;

    if (*idCont == 0)
    {
        printf("Nao ha funcionarios.\n");
        return;
    }
    for (int i = 0; i < *idCont; i++)
    {
        printf("(%d) Nome: %s\n", (*vetor)[i].id, (*vetor)[i].nome);
    }

    printf("Qual funcionario deseja excluir");
    scanf("%d", &id);

    for (int i = 0; i < *idCont; i++)
    {
        if ((*vetor)[i].id != id)
        {
            (*vetor)[cont] = (*vetor)[i];
            cont++;
        }
        else
        {
            encontrado = 1;
        }
    }
      if (encontrado)
    {
        *idCont = cont;

        // Reduz o tamanho do vetor com realloc
        if (*idCont > 0)
        {
            Funcionario *temp = realloc(*vetor, (*idCont) * sizeof(Funcionario));
            if (temp != NULL)
            {
                *vetor = temp;
            }
        }
        else
        {
            // Se não houver funcionários, libera a memória
            free(*vetor);
            *vetor = NULL;
        }

        printf("Funcionario removido com sucesso.\n");
    }
    else
    {
        printf("Nao existe funcionario com esse ID.\n");
    }
}
void atualizarFuncionario(Funcionario *vetor, int *idCont, int *ultimoId)
{
    int id;
    char y;
    int encontrado = 0;

    if (*idCont == 0)
    {
        printf("Nao ha funcionarios.\n");
        return;
    }
    int num = *ultimoId;
    listarFuncionarios(vetor, idCont, 4, &num);

    printf("Digite o ID do funcionario a atualizar: ");
    scanf("%d", &id);

    for (int i = 0; i < *idCont; i++)
    {
        if (vetor[i].id == id)
        {
            printf("Funcionario encontrado: %s\n", vetor[i].nome);
            printf("Tem certeza? [s/n]: ");
            scanf(" %c", &y);

            if (y == 's' || y == 'S')
            {
                printf("Novo nome: ");
                scanf(" %[^\n]", vetor[i].nome);
                printf("Funcionario atualizado com sucesso!\n");
            }
            else
            {
                printf("Atualizacao cancelada.\n");
            }

            encontrado = 1;
            break; // já atualizou, pode sair
        }
    }

    if (!encontrado)
    {
        printf("Nao existe funcionario com esse ID.\n");
    }
}

int menu(int op)
{

    printf("1. Inserir funcionário\n"
           "2. Listar funcionários ordenados por ID\n"
           "3. Listar funcionários ordenados por nome\n"
           "4. Listar funcionários por ordem de inserção\n"
           "5. Apagar funcionário (por ID)\n"
           "6. Atualizar funcionário (por ID)\n"
           "7. Sair\n");
    scanf("%d", &op);
    return op;
}

int main()
{
    int idCont = 0;
    int ultimoId = 0;
    Funcionario *vetor=NULL;
    Funcionario funcionario;
    int op = 0;

    do
    {
        op = menu(op);
        switch (op)
        {
        case 1:
            inserirFuncionario(&vetor, &idCont, &ultimoId);
            break;
        case 3:
            listarFuncionariosPorNome(vetor, &idCont);
            break;
        case 2:
        case 4:
            listarFuncionarios(vetor, &idCont, op, &ultimoId);
            break;
        case 5:
            apagarFuncionario(&vetor, &idCont);
            break;
        case 6:
            atualizarFuncionario(vetor, &idCont, &ultimoId);
            break;
        default:
            break;
        }

    } while (op != 7);
    
    free(vetor);
    return 0;
}