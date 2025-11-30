#include <stdio.h>
#include <locale.h>

/*
Faz um programa em C que permita ao utilizador escolher
entre calcular a área de um quadrado, retângulo ou triângulo
 retângulo. Pede os dados necessários para o cálculo e mostra
 o resultado. Utiliza um switch case para permitir que o
 utilizador faça a escolha.
 */

int main()
{
    setlocale(LC_ALL, "Portuguese_Portugal.1252");

    int opcao;
    float lado, base, altura, area;

    printf("=== Cálculo de Áreas ===\n");
    printf("Escolha uma figura:\n");
    printf("1 - Quadrado\n");
    printf("2 - Retângulo\n");
    printf("3 - Triângulo retângulo\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("\nDigite o valor do lado do quadrado: ");
        scanf("%f", &lado);
        area = lado * lado;
        printf("A área do quadrado é: %.2f\n", area);
        break;

    case 2:
        printf("\nDigite o valor da base do retângulo: ");
        scanf("%f", &base);
        printf("Digite o valor da altura do retângulo: ");
        scanf("%f", &altura);
        area = base * altura;
        printf("A área do retângulo é: %.2f\n", area);
        break;

    case 3:
        printf("\nDigite o valor da base do triângulo retângulo: ");
        scanf("%f", &base);
        printf("Digite o valor da altura do triângulo retângulo: ");
        scanf("%f", &altura);
        area = (base * altura) / 2;
        printf("A área do triângulo retângulo é: %.2f\n", area);
        break;

    default:
        printf("\nOpção inválida! Por favor, escolha 1, 2 ou 3.\n");
    }

    return 0;
}