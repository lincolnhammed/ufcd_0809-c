#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int *p = (int*)malloc(5*sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        p[i] = i+1;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n",p[i]);
    }
    printf("\n"); //Diminui o tamanho do array

    p = realloc(p,3*sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        printf("%d\n",p[i]);
    }
    printf("\n"); //Aumenta o tamanho do array
    p = realloc(p,10*sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n",p[i]);
    }



    return 0;
}
 