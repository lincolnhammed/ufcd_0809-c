#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
2.	Escreva um programa em C que leia duas matrizes de 2 colunas e 2 linhas e calcule a soma 
delas. O programa deve exibir a matriz resultante da adição.
1 2        2 1        3 3
2 3        1 2        3 5
 */

int main()
{
    srand(time(NULL));
    int matriz_A[2][2];
    int matriz_B[2][2];
    int matriz_resultado[2][2];

    // Adicionando valores com randomico na matriz A
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            matriz_A[i][j] = rand() % 10;
        }
        
    }
    // Adicionando valores com randomico na matriz B
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            matriz_B[i][j] = rand() % 10;
        }
    }

    // apresentando valores da matriz A
    printf("Matriz A\n");
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            printf("%d ", matriz_A[i][j]);
        }
        printf("\n");
    }

    // apresentando valores da matriz B
    printf("Matriz B\n");
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            printf("%d ", matriz_B[i][j]);
        }
        printf("\n");
    }

    // Fazendo a soma das matrizes
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {

            matriz_resultado[i][j] = matriz_A[i][j] + matriz_B[i][j];
        }
    }

    // Mostrando resultado
    printf("Resultado\n");
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            if (j == 0)
            {

                for (size_t j = 0; j < 2; j++)
                {
                    printf("%d ", matriz_A[i][j]);
                }

                printf(" ");

                for (size_t j = 0; j < 2; j++)
                {
                    printf("%d ", matriz_B[i][j]);
                }
                printf(" ");
            }
            printf("%2.d ", matriz_resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}