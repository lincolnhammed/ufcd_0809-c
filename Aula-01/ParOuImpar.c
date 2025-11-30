#include <stdio.h>

/*
Solicite ao utilizador um número inteiro e, em seguida,
verifique e mostre se o número é par ou ímpar.
 */

int main()
{

    int num = 0;

    printf("Digite um numero inteiro e veja se é impar ou par\n");
    scanf("%d",&num);

    if (num % 2 == 0)
        printf("O numero %d é par", num);
    else
        printf("O numero %d é impar", num);

    return 0;
}