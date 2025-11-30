#include <stdio.h>

/* 
Escreva uma função que verifica se é possível formar um triângulo com três medidas passadas por parâmetro.
 A função deve devolver 1 se for possível e 0 caso contrário.
a + b > c
b + c > a
a + c > b
 */

#include <stdio.h>

int verificaTriangulo(float a, float b, float c) {
    if (a < b + c && b < a + c && c < a + b) {
        return 1;   // é triângulo
    } else {
        return 0;   // não é triângulo
    }
}

int main() {
    float a, b, c;

    printf("Digite os tres lados: ");
    scanf("%f %f %f", &a, &b, &c);


    printf("resultado:\n%d\n", verificaTriangulo(a, b, c));

    return 0;
}


