#include <stdio.h>
#define MAX 10
#include <stdlib.h>
#include <time.h>
/* 
Crie um programa que preencha aleatoriamente um vetor 
com 10 números inteiros no intervalo de 0 a 5 e mostre
 o vetor. Em seguida, o programa deve contar quantas vezes 
 um determinado número, fornecido pelo utilizador, aparece 
  vetor. O programa deve continuar a permitir a procura de 
  números até que o utilizador insira -1, momento em que o
   programa deve terminar.
 */

int main() {
    
    int randon=0; 
    int num[MAX];
    int numUsuario=0;
    int cont=0;
  srand(time(NULL));
    do{
   
    
        for (size_t i = 0; i < MAX; i++)
        {

            randon = rand() % 5;
            num[i] = randon;

        }

        printf ("Digite um numero\n");
        scanf("%d",&numUsuario);
        for (size_t i = 0; i < MAX; i++)
        {
            
            printf("%5d",num[i]);
            if (numUsuario == num[i])
            {
               cont++;
            }
            
        }
        printf("\n");
        printf("quantidade de numeros iguais é: %d\n",cont);

        cont=0;
        }while (numUsuario!=-1);


    return 0;
}