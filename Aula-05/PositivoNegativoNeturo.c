#include <stdio.h>
#define MAX 6
/* 

 */

int main() {

    int num[MAX];
    for (int i = 0; i < MAX; i++)
    {
        printf("Digite o %d° numero", i+1);
        scanf("%d",& num[i]);
    }
    
int contMaior=0;
int contMenor=0;
int contNeutro=0;

    for (size_t i = 0; i < MAX; i++)
    {
        if (num[i]>0){
            contMaior++;
        }else if(num[i]<0){
            contMenor++;
        }else
            contNeutro++;
    }
     printf("vetor do vetor\n");
    for (size_t i = 0; i < MAX; i++)
    {
        printf("%5d",num[i]);
    }
     printf("\n");
     printf("Contagem de numeros positivos é: %d\n",contMaior);
     printf("Contagem de numeros Negativos é: %d\n",contMenor);
     printf("Contagem de numeros Negativos é: %d\n",contNeutro);
    

    return 0;
}