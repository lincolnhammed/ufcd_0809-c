#include <stdio.h>

typedef struct 
{
    int id;
    char nome[10];
    int idade;
}testePonteiro;

void testes(testePonteiro *teste){

    printf("estou aqui");
}
int main() {

   
testePonteiro *teste =NULL;




testes(teste);

    return 0;
}