#include <stdio.h>
#define MAX 4
/* 
Crie um programa que declare um vetor de 4 decimais. Solicite ao utilizador que 
insira os valores e, de seguida, exiba os valores do vetor na ordem inversa.  
Deverá mostrar um menu que possibilita que o utilizar volte a inserir novos 
valores para o vetor:
##menu##
1-Inserir valores
0-Sair
 */

int main() {

    int num[MAX];
    int op=0;

     do{
        printf("Escolha uma opção\n");
        printf("===================================\n");
        printf("[1] Inserir Valores\n");
        printf("[0] Sair\n");
        printf("===================================\n");
        scanf("%d",&op);
    switch (op)
    {
    case 1:
         for(int i=0;i<MAX;i++){
        printf("digite o %d numero\n", i+1);
        scanf("%d",&num[i]);
        printf("===================================\n");
    }
        printf("\n-> Vetor inverso\n");
        
    for(int y=MAX-1;y>=0;y--){
       
        printf("%5d", num[y]);
        
        
    }
printf("\n\n");
        break;
    
    default:
 printf("Numero invalido");
        break;
    }
   
 printf("===================================\n");
   

    }while (op!=0);
   
    printf("FIM");
    return 0;
}