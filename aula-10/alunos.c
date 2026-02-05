#include <stdio.h>
#include <locale.h>
#define MAX 3
#define TAM 50
#define MAX_NOME 50
typedef struct
{
    int numero;
    char nome[MAX_NOME];
    float n1, n2, n3;
} Aluno;
void menu_principal(int *op);
void inserir_aluno(Aluno v_alunos[], int *pos);
void mostrar_alunos(Aluno v_alunos[], int qt_alunos);
void inserir_varios_alunos(Aluno *v_alunos, int *pos);
void procurar_mostrar_aluno(Aluno v_alunos[], int pos);
int main()
{
    int opcao, pos = 0;
    Aluno v_alunos[TAM]; // vetor da estrutura aluno
    setlocale(LC_ALL, "Portuguese");
    do
    {
        menu_principal(&opcao);
        switch (opcao)
        {
        case 1:
            inserir_aluno(v_alunos, &pos);
            break;

        case 2:
            inserir_varios_alunos(v_alunos, &pos);
            break;
        case 4:
            mostrar_alunos(v_alunos, pos);
            break;
        case 5:
            procurar_mostrar_aluno(v_alunos, pos);
            break;
        }

    } while (opcao != 0);
    /*

    printf("Dados do aluno %d:\n1ªNota %.2f\n2ªNota %.2f\n3ªNota %.2f",
           v_alunos[0].numero, v_alunos[0].n1, v_alunos[0].n2, v_alunos[0].n3);*/
    return 0;
}

void menu_principal(int *op) // op<- 0x04
{
    printf("1-Inserir aluno\n"
           "2-Inserir vários alunos\n"
           "3-Remover aluno\n"
           "4-Listar Alunos\n"
           "5-Procurar um aluno\n"
           "6-Ordenar alunos\n"
           "0-Sair\n");
    scanf("%d", op); // op <- end de memória, ou seja, 0x002
}
void inserir_aluno(Aluno v_alunos[], int *pos) // 0x3
{
    printf("Insira o número do aluno\n");
    scanf("%d", &v_alunos[*pos].numero); // 0
    printf("Insira o nome do aluno\n");
    scanf("%s", v_alunos[*pos].nome);
    printf("Insira a 1ª nota\n");
    scanf("%f", &v_alunos[*pos].n1);
    printf("Insira a 2ª nota\n");
    scanf("%f", &v_alunos[*pos].n2);
    printf("Insira a 3ª nota\n");
    scanf("%f", &v_alunos[*pos].n3);
    (*pos)++;
}

void inserir_varios_alunos(Aluno *v_alunos, int *pos)
{
    int quantidade = 0;
    printf("quantos alunos inserir");
    scanf("%d", &quantidade);
    int p_inicial = *pos;
    for (int i = p_inicial; i < p_inicial + quantidade; i++)
    {
        printf("Insira o número do aluno\n");
        scanf("%d", &v_alunos[*pos].numero); // 0
        printf("Insira o nome do aluno\n");
        scanf("%s", v_alunos[*pos].nome);
        printf("Insira a 1ª nota\n");
        scanf("%f", &v_alunos[*pos].n1);
        printf("Insira a 2ª nota\n");
        scanf("%f", &v_alunos[*pos].n2);
        printf("Insira a 3ª nota\n");
        scanf("%f", &v_alunos[*pos].n3);
        (*pos)++;
    }
}

int procurar_devolve_aluno(Aluno *v_aluno, int qt_alunos)
{
    /*
    printf qual o número do aluno
    se encontra devolve o número

    se não encontrar devolve -1

    */
}

void procurar_mostrar_aluno(Aluno v_alunos[], int pos)
{
       mostrar_alunos(v_alunos,pos);
   int n;
 
    printf("Qual o número do aluno que quer ver?\n");
    scanf("%d", n);
 
    for (int i = 0; i < pos; i++)
    {
        if(n == v_alunos[i].numero)
           {
 
            return i;
           }
    }
    return -1;

       
    
}

void mostrar_alunos(Aluno v_alunos[], int qt_alunos)
{
    for (int i = 0; i < qt_alunos; i++)
        printf("%dºAluno: %s\n1ª Nota:%.2f\n2ª Nota:%.2f\n3ª Nota:%.2f\n",
               v_alunos[i].numero, v_alunos[i].nome, v_alunos[i].n1,
               v_alunos[i].n2, v_alunos[i].n3);
}

/*
menu:
1-Inserir aluno ok
2-Inserir vários alunos
3-Remover aluno
4-Listar Alunos +-
5-Procurar um aluno
6-Ordenar alunos
7-Alterar aluno
0-Sair
*/
