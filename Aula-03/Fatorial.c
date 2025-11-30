/* 
Crie um procedimento chamada fatorial que calcule o fatorial de um número recebido por parâmetro e o imprima no ecrã.
Exemplo:
4! = 1x2x3x4
 */
#include <stdio.h>
/**
 * Função: fatorial
 * Autor(a): Formando Tamara
 * Descrição: Recebe 1 inteiros e devolve o fatorial.
 */
void fatorial(int num){
    long long resultado=num;
    for (int i = num-1; i >0; i--)
    {
         resultado*=i;
    }
    printf("resultado fatorial = %lld\n",resultado);
}
 /**
 * Função principal do programa
 * Autor: Formando Lincoln
 */
int main() {
int n1;
    printf("Digite um numero e descubra o fatorial");
    scanf("%d",&n1);
    fatorial(n1);

    return 0;
}
/*
 void fatorial(int num){
int resultado=num;

printf("%d! = ",num);

for (int i = num; i >=1; i--)
{
    printf("%d",i);
    if(i>1){
        printf("*");
    }
    if(num>i){
    resultado*=i;
    }

}
printf("= %d\n",resultado);

 }
*/