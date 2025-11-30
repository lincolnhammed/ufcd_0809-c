#include <stdio.h>
#define MAX 4
/* 
Crie um programa que declare um vetor de 8 decimais. Solicite ao utilizador 
que insira os valores e, de seguida, encontre e exiba a média, o maior e o 
menor valor presente no vetor.
 */

int main() {

    int num[MAX];
    float soma=0;
    int maior=0;
    int menor=0;
    for (size_t i = 0; i < MAX; i++)
    {
       printf("Digite o %d° numero", i+1);
        scanf("%d",&num[i]);
        soma+=num[i];
    }
maior = num[0];
menor = num[0];

    for (size_t i = 0; i < MAX; i++)
    {
    
          if (num[i] > maior) 
              maior = num[i];
         if (num[i] < menor)
              menor = num[i];
    
        
    }

    printf("A media dos vetor é %.2f",soma/MAX);
    printf("O maior numero é %d",maior);
    printf("o menor numero é %d",menor);

    


    
    

    return 0;
}