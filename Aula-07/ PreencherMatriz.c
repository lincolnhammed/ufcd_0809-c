#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 4
#define COLUNA 3

/*
1.	Escreve um programa que preencha de forma aleatória uma matriz de inteiros
de 4 linha por 3 colunas e que a mostre no ecrã com a seguinte aparência:
?|?|?
-------
?|?|?
-------
?|?|?
-------
?|?|?
 */

int main()
{
    srand(time(NULL));
    int matriz[LINHA][COLUNA];
    for (size_t i = 0; i < LINHA; i++)
    {
        for (size_t j = 0; j < COLUNA; j++)
        {
            matriz[i][j] = rand() % 10;
            printf("%d", matriz[i][j]);
            if (j < 2)
            {
                printf("%s", "|");
            }
        }
        if (i < 3)
        {
            printf("\n-----\n");
        }
    }

    printf("\n\nFim");
    return 0;
}