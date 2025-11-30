#include <stdio.h>
#define MAX 4
#include <stdlib.h>
#include <time.h>
/* 
Crie um programa que leia 5 números inteiros, 
armazene-os num vetor e remova todos os elementos
 iguais a um valor fornecido pelo utilizador. 
 No final, deve mostrar o vetor compactado
 */

int main() {
    

    int num[MAX];
    int numUsuario=0;
    int cont=0;
 
    for (size_t i = 0; i < MAX; i++)
    {
       printf("Digite o %d° numero", i+1);
        scanf("%d",&num[i]);      
    }
        printf ("Digite usuuario\n");
        scanf("%d",&numUsuario);
        for (size_t i = 0; i < MAX; i++)
        {
            if (numUsuario != num[i] )
            {
               num[i]= num[i];
               printf("%5d",num[i]);
            }  
        }
    return 0;
}