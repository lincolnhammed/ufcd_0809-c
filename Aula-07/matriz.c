#include <stdio.h>

#define MAX_ALUNOS 2
#define MAX_TESTES 3

int menu() {
    int opcao;
    printf("\nMenu de opções:\n");
    printf("1 - inserir notas\n");
    printf("2 - mostrar notas\n");
    printf("0 - sair\n");
    printf("Opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main() {
    float notas[MAX_ALUNOS][MAX_TESTES] = {0};
    char nomeAlunos[MAX_ALUNOS][50] = {{0}};
    int op;
    int dadosInseridos = 0;

    do {
        op = menu();

        switch (op) {
            case 1:
                for (int i = 0; i < MAX_ALUNOS; i++) {
                    printf("Inserir o nome do aluno %d:\n", i + 1);

                    // ✅ PASSA a linha (char*) e não a matriz toda nem &nomeAlunos[i]
                    scanf("%49s", nomeAlunos[i]);

                    for (int j = 0; j < MAX_TESTES; j++) {
                        printf("Inserir a nota %d do aluno %s:\n", j + 1, nomeAlunos[i]);

                        // ✅ %f com &notas[i][j] (float*)
                        scanf("%f", &notas[i][j]);
                    }
                }
                dadosInseridos = 1;
                break;

            case 2:
                if (!dadosInseridos) {
                    printf("Ainda nao inseriste dados (usa a opcao 1 primeiro).\n");
                    break;
                }
            

                for (int i = 0; i < MAX_ALUNOS; i++) {
                    printf("\nAluno %d: %s\n", i + 1, nomeAlunos[i]);
                    for (int j = 0; j < MAX_TESTES; j++) {
                        printf("  Teste %d: %.2f\n", j + 1, notas[i][j]);
                    }
                }
                break;

            case 0:
                printf("A sair...\n");
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }

    } while (op != 0);

    return 0;
}


/*

int main()
{
    int op, naluno, periodo;
    float notas[TESTES][ALUNOS]; //declaração de matriz

    for (int i=0; i<TESTES; i++)
        for(int j=0; j<ALUNOS; j++)
            notas[i][j]=-1;

    do
    {
        op=menu();
        switch(op)
        {
        case 1:
            printf("Insira o número do aluno\n");
            scanf("%d",&naluno);
            printf("Qual o período?(1º | 2º |3º)\n");
            scanf("%d", &periodo);
            printf("Insira a nota\n");
            scanf("%f", &notas[periodo-1][naluno-1]);
            break;
        case 2:
            printf("Qual aluno?\n");
            scanf("%d", &naluno);
            for (int i=0; i<TESTES; i++)
                if(notas[i][naluno-1]==-1)
                    printf("%d-nota Sem Nota\n", i+1);
                else
                    printf("%d-nota %.2f\n", i+1, notas[i][naluno-1]);
            break;
        case 3:
                for(int j=0; j<ALUNOS; j++)
                {
                    printf("Aluno %d\n", j+1);
                    for (int i=0; i<TESTES; i++)
                    if(notas[i][j]==-1)
                        printf("%dª nota: Sem Nota\n", i+1);
                            else
                        printf("%dª nota: %.2f\n",i+1, notas[i][j]);
                }

                    break;

        default:
            printf("Opção inválida");

        }
    }
    while(op!=0);
    return 0;
}

int menu()
{
    int op;
    printf("1-Inserir nota\n");
    printf("2-Mostrar nota\n");
    printf("3-Mostrar todas as notas\n");
    printf("0-Sair\n");
    scanf("%d",&op);
    return op;
}   Isto é um comentário
   de várias linhas
*/