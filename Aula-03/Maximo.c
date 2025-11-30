/* 
Crie uma função chamada maximo que receba três números inteiros e devolva o maior deles.
 */

#include <stdio.h>
/**
 * Função: maximo
 * Autor(a): Formando Tamara
 * Descrição: Recebe 3 inteiros e devolve o maior.
 */
int maximo(int a,int b,int c){
 
    int maior=a;

    if (a > maior) maior = a;
    if (b > maior) maior = b;
    if (c > maior) maior = c;
 
     return(maior);
}
/**
 * Função principal do programa
 * Autor: Formando Lincoln
 */
int main() {
int num1,num2,num3;
    
    printf("descubra qual o maior numero");
    printf("digite o primeiro numero");
    scanf(" %d",&num1);
    printf("digite o segundo numero");
    scanf(" %d",&num2);
    printf("digite o terceiro numero");
    scanf(" %d",&num3);
    printf("O maior numero é %d",maximo(num1,num2,num3));

    return 0;
}
/*
int maximo(int n1,int n2,int n3){

int vetor[2];
vetor[0]=n1;
vetor[1]=n2;
vetor[2]=n3;
int maior;

    maior=vetor[0];

for (int i = 0; i < 3; i++)
{
    if(vetor[i]>maior){
        maior = vetor[i];
    }
}
return maior;
}
*/