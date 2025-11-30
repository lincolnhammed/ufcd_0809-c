#include <stdio.h>

int main() {
    
    char nome[2][50];
    float nota[2][4];
    int y=0;
    int i=0;


    for (i = 0; i < 2; i++)
    {
        printf("digite o %d nome\n :",i + 1);
            scanf(" %[^\n]",nome[i]);
        printf("digite a nota do %s", nome[i]);
        for (y = 0; y < 4; y++)
        {
            printf("digite a %d nota :",y+1);
            scanf("%f",&nota[i][y]);
                
        }     
        printf("\n");
    }
    
    


    


    return 0;
}