#include <stdio.h>
#include <stdbool.h>
/* 
Soma dos Números Pares:
Faça um programa que calcule e mostre a soma dos 
números pares entre 1 e um número inserido pelo utilizador inclusive.
 */

int main() {
    int num=0;
    int soma=0;
    bool continua=true;

  
    printf("digite um numero");
    scanf("%d",&num);

      if(num<2){
            continua=false;
            
        }else{
    for(int i=2;i<=num;i+=2){  
        soma+=i;
printf("numeros pares- %d\n",i);
        
    }
}
    if(continua){
        printf("A soma dos numero pares foi - %d\n",soma);
    }else{
        printf("tente um numero maior ou positivo que %d\n",num);
    }
    

    return 0;
}