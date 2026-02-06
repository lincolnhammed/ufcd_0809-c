#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

/* Protótipos */
char menu_principal();
int ano_atual();
int data_valida(int d, int m, int a);

Data* adicionar_data(Data *v_data, int *qt_datas);
Data* adicionar_varias_datas(Data *v_data, int *qt_datas);
void mostrar_uma_data(Data dat);
void mostrar_todas_datas(Data *v_data, int qt_datas);
int procurar_uma_data(Data *v_data, int qt_datas);
Data* remover_data(Data *v_data, int *qt_datas);
void editar_data(Data *v_data, int qt_datas);
void ordenar_por_ano(Data *v_data, int qt_datas);

int main() {
    setlocale(LC_ALL, "Portuguese");

    Data *v_data = NULL;
    int qt_datas = 0;
    char opcao;

    do {
        opcao = menu_principal();

        switch(opcao) {
            case 'a':
                v_data = adicionar_data(v_data, &qt_datas);
                break;

            case 'j':
                v_data = adicionar_varias_datas(v_data, &qt_datas);
                break;

            case 'm': {
                if(qt_datas == 0) {
                    printf("Não existem datas armazenadas.\n");
                    break;
                }
                int idx = procurar_uma_data(v_data, qt_datas);
                if(idx == -1)
                    printf("Essa data não existe!\n");
                else
                    mostrar_uma_data(v_data[idx]);
                break;
            }

            case 't':
                mostrar_todas_datas(v_data, qt_datas);
                break;

            case 'r':
                v_data = remover_data(v_data, &qt_datas);
                break;

            case 'e':
                editar_data(v_data, qt_datas);
                break;

            case 'o':
                if(qt_datas < 2) {
                    printf("São necessárias pelo menos duas datas para ordenar.\n");
                } else {
                    ordenar_por_ano(v_data, qt_datas);
                }
                break;

            case 's':
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while(opcao != 's');

    free(v_data);
    return 0;
}

/* ================= FUNÇÕES ================= */

char menu_principal() {
    char op;
    printf("\n====== Menu ======\n");
    printf("(a) Adicionar uma data\n");
    printf("(j) Adicionar várias datas\n");
    printf("(m) Mostrar uma data\n");
    printf("(t) Mostrar todas as datas\n");
    printf("(r) Remover uma data\n");
    printf("(e) Editar uma data\n");
    printf("(o) Ordenar por ano\n");
    printf("(s) Sair\n");
    printf("Opção: ");
    scanf(" %c", &op);
    return op;
}

int ano_atual() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    return tm_info->tm_year + 1900;
}

int data_valida(int d, int m, int a) {
    if(d < 1 || d > 31) return 0;
    if(m < 1 || m > 12) return 0;
    if(a < 1 || a > ano_atual()) return 0;
    return 1;
}

Data* adicionar_data(Data *v_data, int *qt_datas) {
    Data temp;

    do {
        printf("Dia: "); scanf("%d", &temp.dia);
        printf("Mês: "); scanf("%d", &temp.mes);
        printf("Ano: "); scanf("%d", &temp.ano);

        if(!data_valida(temp.dia, temp.mes, temp.ano))
            printf("Data inválida! Tente novamente.\n");

    } while(!data_valida(temp.dia, temp.mes, temp.ano));

    Data *novo = realloc(v_data, (*qt_datas + 1) * sizeof(Data));
    if(novo == NULL) {
        printf("Erro de memória!\n");
        return v_data;
    }

    v_data = novo;
    v_data[*qt_datas] = temp;
    (*qt_datas)++;

    return v_data;
}

Data* adicionar_varias_datas(Data *v_data, int *qt_datas) {
    int n;
    printf("Quantas datas deseja adicionar? ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("\nData %d:\n", i + 1);
        v_data = adicionar_data(v_data, qt_datas);
    }
    return v_data;
}

void mostrar_uma_data(Data dat) {
    printf("%02d/%02d/%04d\n", dat.dia, dat.mes, dat.ano);
}

void mostrar_todas_datas(Data *v_data, int qt_datas) {
    if(qt_datas == 0) {
        printf("Nenhuma data registada.\n");
        return;
    }
    for(int i = 0; i < qt_datas; i++) {
        printf("%dª - ", i + 1);
        mostrar_uma_data(v_data[i]);
    }
}

int procurar_uma_data(Data *v_data, int qt_datas) {
    int idx;
    printf("Número da data (1 a %d): ", qt_datas);
    scanf("%d", &idx);

    if(idx < 1 || idx > qt_datas)
        return -1;

    return idx - 1;
}

Data* remover_data(Data *v_data, int *qt_datas) {
    if(*qt_datas == 0) {
        printf("Não existem datas para remover.\n");
        return v_data;
    }

    int idx = procurar_uma_data(v_data, *qt_datas);
    if(idx == -1) {
        printf("Data inexistente.\n");
        return v_data;
    }

    for(int i = idx; i < *qt_datas - 1; i++)
        v_data[i] = v_data[i + 1];

    (*qt_datas)--;

    Data *novo = realloc(v_data, (*qt_datas) * sizeof(Data));
    if(novo || *qt_datas == 0)
        v_data = novo;

    printf("Data removida com sucesso.\n");
    return v_data;
}

void editar_data(Data *v_data, int qt_datas) {
    if(qt_datas == 0) {
        printf("Não existem datas para editar.\n");
        return;
    }

    int idx = procurar_uma_data(v_data, qt_datas);
    if(idx == -1) {
        printf("Data inexistente.\n");
        return;
    }

    Data temp;
    do {
        printf("Novo dia: "); scanf("%d", &temp.dia);
        printf("Novo mês: "); scanf("%d", &temp.mes);
        printf("Novo ano: "); scanf("%d", &temp.ano);

        if(!data_valida(temp.dia, temp.mes, temp.ano))
            printf("Data inválida! Tente novamente.\n");

    } while(!data_valida(temp.dia, temp.mes, temp.ano));

    v_data[idx] = temp;
    printf("Data editada com sucesso.\n");
}

void ordenar_por_ano(Data *v_data, int qt_datas) {
    for(int i = 0; i < qt_datas - 1; i++) {
        for(int j = 0; j < qt_datas - i - 1; j++) {
            if(v_data[j].ano > v_data[j + 1].ano ||
              (v_data[j].ano == v_data[j + 1].ano &&
               v_data[j].mes > v_data[j + 1].mes) ||
              (v_data[j].ano == v_data[j + 1].ano &&
               v_data[j].mes == v_data[j + 1].mes &&
               v_data[j].dia > v_data[j + 1].dia)) {

                Data tmp = v_data[j];
                v_data[j] = v_data[j + 1];
                v_data[j + 1] = tmp;
            }
        }
    }
    printf("Datas ordenadas cronologicamente.\n");
}
