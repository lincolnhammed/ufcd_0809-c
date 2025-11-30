#include <stdio.h>

/**
 * Função: quadrado
 * Autor(a): Formando Tamara
 * Descrição: Fazendo A soma de um quadrado.
 */
int quadrado(int n){
        int resultado = n*n;
    return resultado;
}
/**
 * Função principal do programa
 * Autor: Formando Lincoln
 */
int main() {
    int num;
    printf("Descubra o quadrado de um numero");
    scanf(" %d",&num);
    printf("O quadrado do numero %d é %d ",num,quadrado(num));
    return 0;
}

