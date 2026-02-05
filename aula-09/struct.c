#include <stdio.h>
#define MAX 3

struct aluno
{
    int id;
    char nome[50];
    float nota[MAX];
};

int main()
{
    struct aluno a1 = {4, "LINCOLN", {1.0, 2.0, 3.0}};

    printf("ID do aluno: %d\n", a1.id);
    printf("Nome do aluno: %s\n", a1.nome);
    printf("Notas: ");
    for(int i=0; i<MAX; i++)
    {
        printf("%.1f ", a1.nota[i]);
    }
    printf("\n");

    // Exemplo de ler dados do usuário
    printf("Insira o ID do aluno: ");
    scanf("%d", &a1.id);

    printf("Insira o nome do aluno: ");
    scanf("%49s", a1.nome);

    for(int i=0; i<MAX; i++)
    {
        printf("Insira a nota %d: ", i+1);
        scanf("%f", &a1.nota[i]);
    }

    printf("\nAluno atualizado:\n");
    printf("ID: %d\n", a1.id);
    printf("Nome: %s\n", a1.nome);
    printf("Notas: ");
    for(int i=0; i<MAX; i++)
    {
        printf("%.1f ", a1.nota[i]);
    }
    printf("\n");

    return 0;
}
