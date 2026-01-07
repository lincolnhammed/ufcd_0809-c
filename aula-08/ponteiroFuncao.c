#include <stdio.h>

int main()
{
    int n1;
    int *v1;
    printf("Insira um valor\n");
    scanf("%d", &n1);
    aumenta(&n1);

    printf("na main %d\n", n1);
    return 0;
}


void aumenta (int *valor)
{
    printf("na funcao %d\n", *valor);//12
    (*valor)++; //13
}
 