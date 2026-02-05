#include <stdio.h>

int main()
{
    int n1=3, n2=5;
    int *p;
    trocar_2numeros_ref(&n1, &n2);
    //trocar_2numeros_valor(n1,n2);
    printf("na main: Numero1: %d | Numero2: %d", n1, n2);
    return 0;
}


/*Crie uma função que troque o valor de dois números inteiros
passados por referência.     a=3 b=5
                             b=3 a=5*/

void trocar_2numeros_valor(int numero1, int numero2)
{
    printf("antes: Numero1: %d | Numero2: %d\n", numero1, numero2);
    int aux=numero1;
    numero1=numero2;
    numero2=aux;
    printf("depois: Numero1: %d | Numero2: %d\n", numero1, numero2);
}


void trocar_2numeros_ref(int *numero1, int *numero2)
{
    printf("antes: Numero1: %d | Numero2: %d\n", *numero1, *numero2);
    int aux=*numero1;
    *numero1=*numero2;
    *numero2=aux;
    printf("depois: Numero1: %d | Numero2: %d\n", *numero1, *numero2);
}
 