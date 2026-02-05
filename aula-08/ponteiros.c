#include <stdio.h>

/* 

 */

int main()
{
    int valor1 , *p;
    p=&valor1;

    scanf("%d", &valor1);

    printf("valor de valor1 %d\n", valor1);
    printf("valor para onde aponta p %d\n\n", *p);
    *p =123;

    printf("valor de valor1 %d\n", valor1);
    printf("valor para onde aponta p %d\n", *p);

    scanf("%d", p); //&valor1 p

        printf("valor de valor1 %d\n", valor1);
    printf("valor para onde aponta p %d\n", *p);

    printf("endereco de memoria %p %p",&valor1,p);

    return 0;
}