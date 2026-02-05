#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

/* Protótipos */
void menu_principal(char *op);
void adicionar_data(Data **v_data, int *qt_datas);
void mostrar_todas_datas(Data *v_data, int qt_datas);
void remover_data(Data **v_data, int *qt_datas);

int main() {
    setlocale(LC_ALL, "Portuguese");

    Data *v_data = NULL;
    int qt_datas = 0;
    char opcao;

    do {
        menu_principal(&opcao);

        switch (opcao) {
            case 'a':
                adicionar_data(&v_data, &qt_datas);
                break;

            case 't':
                mostrar_todas_datas(v_data, qt_datas);
                break;

            case 'r':
                remover_data(&v_data, &qt_datas);
                break;

            case 's':
                printf("A sair do programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 's');

    free(v_data);
    return 0;
}

/* ===== Funções ===== */

void menu_principal(char *op) {
    printf("\n(a) Adicionar uma data\n");
    printf("(t) Mostrar todas as datas\n");
    printf("(r) Remover uma data\n");
    printf("(s) Sair\n");
    printf("Escolha uma opção: ");
    scanf(" %c", op);  // espaço antes do %c é essencial
}

void adicionar_data(Data **v_data, int *qt_datas) {
    Data *temp = realloc(*v_data, (*qt_datas + 1) * sizeof(Data));

    if (temp == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    *v_data = temp;

    printf("Dia: ");
    scanf("%d", &(*v_data)[*qt_datas].dia);

    printf("Mês: ");
    scanf("%d", &(*v_data)[*qt_datas].mes);

    printf("Ano: ");
    scanf("%d", &(*v_data)[*qt_datas].ano);

    (*qt_datas)++;
}

void mostrar_todas_datas(Data *v_data, int qt_datas) {
    if (qt_datas == 0) {
        printf("Nenhuma data registada.\n");
        return;
    }

    for (int i = 0; i < qt_datas; i++) {
        printf("%dª Data: %02d/%02d/%d\n",
               i + 1,
               v_data[i].dia,
               v_data[i].mes,
               v_data[i].ano);
    }
}

void remover_data(Data **v_data, int *qt_datas) {
    int pos;

    if (*qt_datas == 0) {
        printf("Não há datas para remover.\n");
        return;
    }

    mostrar_todas_datas(*v_data, *qt_datas);

    printf("Qual data deseja remover? ");
    scanf("%d", &pos);

    if (pos < 1 || pos > *qt_datas) {
        printf("Posição inválida!\n");
        return;
    }

    for (int i = pos - 1; i < *qt_datas - 1; i++) {
        (*v_data)[i] = (*v_data)[i + 1];
    }

    (*qt_datas)--;

    *v_data = realloc(*v_data, (*qt_datas) * sizeof(Data));
}
