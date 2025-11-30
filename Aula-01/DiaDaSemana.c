#include <stdio.h>

/*
Escreve um programa em C que peça ao utilizador um número de 1 a 7
representando o dia da semana e mostre o nome correspondente ao dia.
Utiliza um switch case para isso.
 */

int main()
{

    int num = 0;
    printf("Digite um número de 1 a 7 para indicar o dia da semana\n (1 para segunda-feira, 2 para terça-feira, …, 7 para domingo):");
    scanf("%d", &num);
    switch (num)
    {
    case 1:
        printf("segunda-Feira");
        break;
    case 2:
        printf("Terça-Feira");
        break;
    case 3:
        printf("Quarta-Feira");
        break;
    case 4:
        printf("Quinta-Feira");
        break;
    case 5:
        printf("Sexta-Feira");
        break;
    case 6:
        printf("Sabado");
        break;
    case 7:
        printf("Domingo");
        break;
    default:
     printf("Numero invalido");
        break;
    }

    return 0;
}