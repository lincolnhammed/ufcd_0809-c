#include <stdio.h>
#define MAX 4
#include <stdlib.h>
#include <time.h>
/* 
Crie um programa que leia 5 números inteiros, 
armazene-os num vetor e remova todos os elementos
 iguais a um valor fornecido pelo utilizador. 
 No final, deve mostrar o vetor compactado
 */

int main() {

    int num[MAX];
    int numUsuario = 0;
    int cont = 0;

    // Ler números
    for (size_t i = 0; i < MAX; i++) {
        printf("Digite o %d° número: ", i + 1);
        scanf("%d", &num[i]);
    }

    printf("Digite o número a remover: ");
    scanf("%d", &numUsuario);

    // Primeiro conta quantos são diferentes
    for (size_t i = 0; i < MAX; i++) {
        if (num[i] != numUsuario) {
            cont++;
        }
    }

    int num2[cont]; // vetor compactado
    int j = 0;      // índice correto para num2

    // Copiar somente os diferentes
    for (size_t i = 0; i < MAX; i++) {
        if (num[i] != numUsuario) {
            num2[j] = num[i];
            j++;
        }
    }

    // Mostrar vetor compactado
    printf("\nVetor compactado: ");
    for (size_t i = 0; i < cont; i++) {
        printf("%d ", num2[i]);
    }

    printf("\n");
    return 0;
}