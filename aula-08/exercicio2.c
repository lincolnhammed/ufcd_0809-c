#include <stdio.h>
#define MAX 3
void mostrarNotas(float *vetNota, int qpdt) // qpdt - recemendo numero
{
    for (int i = 0; i < qpdt; i++)
    {
        printf("%d° Nota: %.2f\n", i + 1, vetNota[i]);
    }
}
void adicionarVariasNota(float *vetNota, int *pqtd)
{
    if (*pqtd < MAX)
    {
        int x = 0;
        printf("quantas notas quer adcionar (MAXIMO = %d)\n", MAX - *pqtd);
        scanf("%d", &x);
        if (x <= MAX - *pqtd)
        {
            for (int i = *pqtd; i < x + (*pqtd); i++)
            {
                float nota = 0;

                printf("Digire uma nota");
                scanf("%f", &nota);
                vetNota[i] = nota;
                printf("%.2f-----\n", vetNota[i]);
            }
            (*pqtd) += x;
        }
        else
        {
            printf("quantidade invalido (MAXIMO = %d)\n", MAX - *pqtd);
        }
    }
    else
    {
        printf("Nao é possivel add mais notas \n");
    }
}
void adicionarUmaNota(float *vetNota, int *pqtd) // *qpdt - recebendo memoria
{
    if (*pqtd < MAX)
    {
        float nota = 0;
        printf("Digite uma nota");
        scanf("%f", &nota);
        vetNota[*pqtd] = nota;
        (*pqtd)++;
    }
    else
    {
        printf("Nao é possivel add mais notas \n");
    }
}
void removerNota(float *vetNota, int *pqtd)
{
    int cont = 0;
    printf("qual nota deseja excluir\n");
    for (int i = 0; i < *pqtd; i++)
    {
        printf("(%d) nota: %.2f\n", i + 1, vetNota[i]);
    }
    int x = 0;
    scanf("%d", &x);
    for (int i = 0; i < *pqtd; i++)
    {
        if (i + 1 != x)
        {
            vetNota[cont] = vetNota[i];
            cont++;
        }
    }
    (*pqtd)--;

    for (int i = 0; i < *pqtd; i++)
    {
        printf("(%d) nota: %.2f\n", i, vetNota[i]);
    }
}
void calcularMedia(float *vetNota,int qualquercoisa)
{
    float soma=0;
    for (int i = 0; i < qualquercoisa; i++)
    {
        soma+=vetNota[i];
        
    }

    printf("media é ->%.2f\n",soma/qualquercoisa);
}
int menu(int op)
{
    do
    {
        printf(
            "1 – Adicionar uma nota\n"
            "2 – Adicionar várias notas\n"
            "3 – Remover uma nota\n"
            "4 – Calcular e mostrar a média\n"
            "5 – Mostrar todas as notas\n"
            "0 – Sair\n");
        scanf("%d", &op);
        if (op > 5 || op < 0)
        {
            printf("##########################");
            printf("\nnumero invalido\nEscolha uma opcao valida\n");
            printf("##########################\n");
        }
    } while (op > 5 || op < 0);
    return op;
}

int main()
{
    float vetNota[MAX];
    int op = 0;
    int *pqtd, qtd = 0;
    pqtd = &qtd;

    do
    {
        op = menu(op);
        switch (op)
        {
        case 1:
            printf("chegou aqui add notas\n");
            adicionarUmaNota(vetNota, pqtd); // opontando memoria
            break;
        case 2:
            printf("chegou aqui add notas\n");
            adicionarVariasNota(vetNota, pqtd); // opontando memoria
            break;
        case 3:
            printf("chegou aqui add notas\n");
            removerNota(vetNota, pqtd); // opontando memoria
            break;
        case 4:
            printf("chegou aqui calcularMedia\n");
            calcularMedia(vetNota,*pqtd); // apontando numero
            break;
        case 5:
            printf("chegou aqui mostrar notas\n");
            mostrarNotas(vetNota, *pqtd); // apontando numero
            break;

        default:
            break;
        }

    } while (op != 0);

    printf("\nFIM PROGRAMA\n");
    return 0;
}