#include <stdio.h>

/*
Peça dois números ao utilizador para definir um intervalo e
depois peça um terceiro número para verificar se está dentro desse intervalo.
 */

int main()
{
    int num1, num2, intervalo = 0;
    printf("Digite dois números para definir um intervalo \n(primeiro o limite inferior e depois o limite superior:");
    printf("Digite o primeiro numero");
    scanf("%d", &num1);
    printf("Digite o segundo numero");
    scanf("%d", &num2);

    printf("Agora digite um terceiro número para verificar se está dentro desse intervalo:");

    scanf("%d", &intervalo);

    if (intervalo > num1 && intervalo < num2)

        printf("o numero %d esta entre %d e %d", intervalo, num1, num2);

    else if (intervalo < num1 && intervalo > num2)
        printf("o numero %d esta entre %d e %d", intervalo, num1, num2);

    else
        printf("o numero %d esta fora do intervalo dos numero %d e %d", intervalo, num1, num2);
    return 0;
}