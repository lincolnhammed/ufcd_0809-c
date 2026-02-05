#include <stdio.h>
#include <locale.h>
#define MAX 5

float soma_e_mostra(float *notas, int qt);
void adicionar_nota(float notas[], int *qt_notas);
void mostrar_notas(float *notas, int qt);
void remover_nota(float notas[], int *qt_notas);
void calcular_media(float *notas, int qt_notas);
float calcular_media_2(float *notas, int qt_notas);

int menu();

int main()
{
    float notas[MAX];
    int opcao, qt_notas=0;
    setlocale(LC_ALL, "Portuguese");

    do
    {
        opcao=menu();
        switch(opcao)
        {
        case 1:
            if(qt_notas<MAX)
                adicionar_nota(notas, &qt_notas);//notas-> end. mem do vetor na 1ª posicao
            else
                printf("Atingiu o limite de notas\n");

            break;
        case 2:
            adicionar_varias_notas(notas, &qt_notas);
            break;
        case 5:
            if(qt_notas!=0)
                mostrar_notas(notas, qt_notas);
            else
                printf("Ainda não inseriu nenhuma nota\n");
            break;
        case 3:
            if(qt_notas!=0)
                remover_nota(notas, &qt_notas); //notas[]-> end. memória
            else
                printf("Ainda não inseriu nenhuma nota\n");


            break;

        case 4:
            if(qt_notas!=0)
            {
                calcular_media(notas, qt_notas);
                printf("A média das notas é de %.2f\n",  calcular_media_2(notas, qt_notas) );
            }

            else
                printf("Ainda não inseriu nenhuma nota\n");
        }
    }
    while(opcao!=0);

    /*    for (int i=0; i<2; i++)
        {
            printf("Insira a %dª nota:", i+1);
            scanf("%f", &notas[i]);
        }
        printf("A soma é: %.2f", soma_e_mostra(notas, MAX)); //&notas[0]*/

    return 0;
}

float soma_e_mostra(float *notas, int qt)
{
    float soma=0;
    for (int i=0; i<qt; i++)
    {
        soma+=notas[i];      //*(notas+i)
        printf("%dª nota: %.2f\n", i+1, notas[i]);
    }
    return soma;
}

void mostrar_notas(float *notas, int qt)
{
    for (int i=0; i<qt; i++)
    {
        printf("%dª nota: %.2f\n", i+1, notas[i]);
    }
}



int menu() //int menu(int op, int *ptr) <-Gustavo
{
    int op;
    do
    {
        printf("1 – Adicionar uma nota\n"
               "2 – Adicionar várias notas\n"
               "3 – Remover uma nota\n"
               "4 – Calcular e mostrar a média\n"
               "5 – Mostrar todas as notas\n"
               "0 – Sair\n");
        scanf("%d", &op);
        if(op>5||op<0)
            printf("Opção inválida. Escolha uma opção da lista abaixo\n");
    }
    while(op>5||op<0);   //repete qd verdade
    return op;
}

void adicionar_nota(float notas[], int *qt_notas)
{
    printf("Insira uma nota\n");
    scanf("%f", &notas[*qt_notas]);
    printf("Nota %.2f foi inserida\n", notas[*qt_notas]);
    (*qt_notas)++;
}


void remover_nota(float notas[], int *qt_notas)
{
    int index;
    do
    {
        printf("Qual a nota a remover?\n");
        mostrar_notas(notas, *qt_notas); //notas s/ índice é end. de memória
        scanf("%d", &index);
        if(index<0 || index>*qt_notas)
            printf("Nota inválida, insira uma nota correta!\n");
    }
    while(index<0 || index>*qt_notas);
    
    index--;
    for(int i=index; i<*qt_notas-1; i++)
    {
        notas[i]=notas[i+1];
        printf("%d\n",i);
    }
    (*qt_notas)--;

}

void adicionar_varias_notas(float notas[], int *qt_notas)
{
    int notas_a_inserir;
    printf("Quantas notas quer inserir? %d\n",MAX-*qt_notas); //5-2
    scanf("%d",&notas_a_inserir);
    for(int i=*qt_notas; i<notas_a_inserir+*qt_notas; i++)
    {
        printf("Insira uma nota\n");
        scanf("%f",&notas[i]);

    }
    *qt_notas=*qt_notas+notas_a_inserir;
}

void calcular_media(float *notas, int qt_notas)
{
    float soma=0;

    for (int i=0; i<qt_notas; i++)
        soma+=notas[i];

    printf("A média das notas é de %.2f\n", soma/qt_notas);
}

float calcular_media_2(float *notas, int qt_notas)
{
    float soma=0;

    for (int i=0; i<qt_notas; i++)
        soma+=notas[i];

    return soma/qt_notas;
}


/*
Enunciado

Dando continuidade ao exercício realizado em aula, pretende-se desenvolver um programa em C para gerir um conjunto de notas de alunos.
O programa deve utilizar um array de floats com um tamanho máximo definido por uma constante (#define MAX) e todas as funcionalidades devem ser implementadas através de funções.
O programa deve apresentar um menu que permita ao utilizador executar as seguintes opções:

1 – Adicionar uma nota
2 – Adicionar várias notas
3 – Remover uma nota
4 – Calcular e mostrar a média
5 – Mostrar todas as notas
0 – Sair

Requisitos:

As notas devem ser armazenadas num array.
Deve existir uma variável que controle a quantidade de notas inseridas.
Cada opção do menu deve corresponder a uma função específica.
A função main deve limitar-se a:
apresentar o menu
ler a opção escolhida
chamar a função correspondente
A remoção de uma nota deve reorganizar o array, garantindo que não existem posições vazias entre valores.
A média deve ser calculada apenas com as notas efetivamente inseridas.
O programa deve terminar apenas quando o utilizador escolher a opção 0 – Sair.*/





 