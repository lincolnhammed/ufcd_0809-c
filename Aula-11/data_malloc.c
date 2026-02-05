#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
} Data;

Data* adicionar_data(Data *v_data, int *qt_datas);

int main()
{
    Data *v_data;
    int qt_datas=0;
    setlocale(LC_ALL, "Portuguese");
    v_data= adicionar_data(v_data, &qt_datas);
    printf("%d",v_data[0].ano);
    return 0;
}

Data* adicionar_data(Data *v_data, int *qt_datas)
{
    v_data= (Data*) malloc (sizeof(Data));
    v_data[0].dia=10;
    v_data[0].mes=20;
    v_data[0].ano=30;
    (*qt_datas)++;
    return v_data;
}

/*
1)Criar uma estrutura com o nome Data, com os campos dia, mês e ano do tipo inteiro.
Crie as seguintes funções com parâmetros passados por referência.
Função que permita adicionar uma data.
Função que permita mostrar os dados de uma data.

*/
 