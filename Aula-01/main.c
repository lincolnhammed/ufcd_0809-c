#include <stdio.h>
#include <locale.h>
#include <string.h>
#define MAX 50
/*Faça um programa para ler e escrever no ecra os seguintes dados
  Nome pessoa
  peso
  Endereço
  Telefone
  mostre tambem a primeira letra do nome da pessoa
  */

int main()
{
    setlocale(LC_ALL, "pt_PT.UTF-8");
    char nome[50];
    float peso = 0;
    char endereço[MAX];
    char telefone[9];
    int tamanho; 
    printf("Digite seu nome: \n");
    scanf(" %[^\n]", nome);

    printf("%s", nome);
 
    tamanho = strlen(nome);
    for (int i = 0; i < tamanho; i++)
    {

        if ((unsigned char)nome[i] == 0xC3)
        {
            printf("A primeira letra do nome é: %c%c\n", nome[i], nome[i + 1]);
            i++;
        }
        // else
        //   printf("A primeira letra do nome é: %c\n", nome[i]);
    }

    return 0;
}