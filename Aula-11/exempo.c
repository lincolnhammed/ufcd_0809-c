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
void mostra_menu_principal(char *op);
char menu_principal();
void mostrar_todas_datas(Data *v_data, int qt_datas);
void mostrar_uma_data(Data dat);
int procurar_data(Data *v_data, int qt);
void remover_data(Data *v_data, int *qt);

int main()
{
    Data *v_data, *data_aux=NULL;
    int qt_datas=0, uma_data;
    char opcao;
    setlocale(LC_ALL, "Portuguese");
    do
    {
        //mostra_menu_principal(&opcao);
        opcao=menu_principal();
        switch(opcao)
        {
        case 'a':
            if(qt_datas==0)
            {
                data_aux = (Data*)malloc(1*sizeof(Data));//reserva na primeira data
                if (data_aux==NULL)
                {
                    printf("Erro por falta de memória\n");
                    break;
                }
                else
                {
                    v_data=data_aux;
                }
            }
            else
            {
                data_aux = (Data*)realloc(v_data, (qt_datas+1)*sizeof(Data)); //reserva da qt total de datas necessárias
                if (data_aux==NULL)
                {
                    printf("Erro por falta de memória\n");
                    break;
                }
                else
                {
                    v_data=data_aux;
                }
            }
            //v_data = (Data*)calloc(1,sizeof(Data));
            printf("Insira o dia\n");
            scanf("%d", &v_data[qt_datas].dia);
            printf("Insira o mês\n");
            scanf("%d", &v_data[qt_datas].mes);
            printf("Insira o ano\n");
            scanf("%d", &v_data[qt_datas].ano);
            qt_datas++;
            break;
        case 't':
            mostrar_todas_datas(v_data, qt_datas); //(0x25 , 1)
            break;
        case 'r':
            uma_data=procurar_data(v_data, qt_datas); // ( 0x13, 2)
            if (uma_data==-1)
                printf("Essa data não existe!\n");
            else
            {
                for (int i=uma_data; i<qt_datas-1; i++)
                {
                    v_data[i]=v_data[i+1];
                }
                if(qt_datas==1)
                {
                    free(v_data);
                    qt_datas--;
                    printf("Data removida com sucesso\n");
                }
                else
                {
                    data_aux=NULL;
                    data_aux=(Data*)realloc(v_data, (qt_datas-1)*sizeof(Data));
                    if (data_aux==NULL)
                    {
                        printf("Erro a remover a data\n");
                    }
                    else
                    {
                        qt_datas--;
                        printf("Data removida com sucesso\n");
                        v_data=data_aux;
                    }
                }
            }
            //remover_data(v_data, &qt_datas);
            break;
        case 'm':
            uma_data=procurar_data(v_data, qt_datas); // ( 0x13, 2)
            if (uma_data==-1)
                printf("Essa data não existe!\n");
            else
                mostrar_uma_data(v_data[uma_data]);
        }
    }
    while(opcao!='s');
    free(v_data);
    free(data_aux);
    return 0;
}

Data* adicionar_data(Data *v_data, int *qt_datas) // 0x13, 0x26
{
    v_data= (Data*) malloc (sizeof(Data));
    v_data[0].dia=10;
    v_data[0].mes=20;
    v_data[0].ano=30;
    (*qt_datas)++;
    return v_data;
}

void mostra_menu_principal(char *op) //0x002
{
    printf("(a)dicionar uma data.\n"
           "(m)ostrar os dados de uma data.\n"
           "(t)odas as data\n"
           "(r)emover uma data\n"
           "(e)ditar uma data\n"
           "(s)air\n"
           "Escolha uma opção\n");
    fflush(stdin);
    scanf("%c",op);
}

char menu_principal()
{
    char op;
    printf("(a)dicionar uma data.\n"
           "(m)ostrar os dados de uma data.\n"
           "(t)odas as data\n"
           "(r)emover uma data\n"
           "(e)ditar uma data\n"
           "(s)air\n"
           "Escolha uma opção\n");
    fflush(stdin);
    scanf("%c",&op);
    return op;
}

void mostrar_todas_datas(Data *v_data, int qt_datas)
{
    for(int i=0; i<qt_datas; i++)
    {
        printf("%dª ", i+1);
        mostrar_uma_data(v_data[i]);
    }
}

void mostrar_uma_data(Data dat)
{
    printf("Data: %d/%d/%d\n", dat.dia, dat.mes, dat.ano);
}

int procurar_data(Data *v_data, int qt)
{
    int uma_data;
    printf("Qual a data?\n");
    scanf("%d", &uma_data);
    if(uma_data<=qt && uma_data>0)
        return uma_data-1;
    else
        return -1;
}

void remover_data(Data *v_data, int *qt) // 0x17, 0x7 NÃO VAMOS UTILIZAR PARA JÁ
{
    int uma_data;
    Data *v_data_aux;
    uma_data=procurar_data(v_data, *qt); // ( 0x13, 2)
    if (uma_data==-1)
        printf("Essa data não existe!\n");
    else
    {
        for (int i=uma_data; i<(*qt)-1; i++)
        {
            v_data[i]=v_data[i+1];
        }
        (*qt)--;
        printf("Data removida com sucesso\n");
    }
}

/*
1)Criar uma estrutura com o nome Data, com os campos dia, mês e ano do tipo inteiro.
Crie as seguintes funcionalidades:
-adicionar uma data.
-mostrar os dados de uma data.
-remover uma data
*/ 