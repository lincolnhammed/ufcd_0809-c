#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Funções
char menu_principal();
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
                ordenar_por_ano(v_data, qt_datas);
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

// Menu principal
char menu_principal() {
    char op;
    printf("\n====== Menu ======\n");
    printf("(a) Adicionar uma data\n");
    printf("(j) Adicionar várias datas de uma vez\n");
    printf("(m) Mostrar os dados de uma data\n");
    printf("(t) Mostrar todas as datas\n");
    printf("(r) Remover uma data\n");
    printf("(e) Editar uma data\n");
    printf("(o) Ordenar as datas por ano\n");
    printf("(s) Sair\n");
    printf("Escolha uma opção: ");
    scanf(" %c", &op);
    return op;
}

// Adicionar uma data
Data* adicionar_data(Data *v_data, int *qt_datas) {
    Data *novo = realloc(v_data, (*qt_datas + 1) * sizeof(Data));
    if(novo == NULL) {
        printf("Erro de memória!\n");
        return v_data;
    }
    v_data = novo;
    printf("Insira o dia: ");
    scanf("%d", &v_data[*qt_datas].dia);
    printf("Insira o mês: ");
    scanf("%d", &v_data[*qt_datas].mes);
    printf("Insira o ano: ");
    scanf("%d", &v_data[*qt_datas].ano);
    (*qt_datas)++;
    return v_data;
}

// Adicionar várias datas
Data* adicionar_varias_datas(Data *v_data, int *qt_datas) {
    int n;
    printf("Quantas datas deseja adicionar? ");
    scanf("%d", &n);
    if(n <= 0) return v_data;

    Data *novo = realloc(v_data, (*qt_datas + n) * sizeof(Data));
    if(novo == NULL) {
        printf("Erro de memória!\n");
        return v_data;
    }
    v_data = novo;
    for(int i = 0; i < n; i++) {
        printf("\nData %d:\n", i+1);
        printf("Dia: "); scanf("%d", &v_data[*qt_datas].dia);
        printf("Mês: "); scanf("%d", &v_data[*qt_datas].mes);
        printf("Ano: "); scanf("%d", &v_data[*qt_datas].ano);
        (*qt_datas)++;
    }
    return v_data;
}

// Mostrar uma data
void mostrar_uma_data(Data dat) {
    printf("Data: %02d/%02d/%04d\n", dat.dia, dat.mes, dat.ano);
}

// Mostrar todas as datas
void mostrar_todas_datas(Data *v_data, int qt_datas) {
    if(qt_datas == 0) {
        printf("Nenhuma data cadastrada.\n");
        return;
    }
    for(int i = 0; i < qt_datas; i++) {
        printf("%dª ", i+1);
        mostrar_uma_data(v_data[i]);
    }
}

// Procurar uma data pelo índice
int procurar_uma_data(Data *v_data, int qt_datas) {
    if(qt_datas == 0) return -1;
    int idx;
    printf("Qual o número da data (1 a %d)? ", qt_datas);
    scanf("%d", &idx);
    if(idx < 1 || idx > qt_datas) return -1;
    return idx - 1;
}

// Remover data
Data* remover_data(Data *v_data, int *qt_datas) {
    if(*qt_datas == 0) {
        printf("Nenhuma data para remover.\n");
        return v_data;
    }
    int idx = procurar_uma_data(v_data, *qt_datas);
    if(idx == -1) {
        printf("Essa data não existe!\n");
        return v_data;
    }
    for(int i = idx; i < (*qt_datas) - 1; i++) {
        v_data[i] = v_data[i + 1];
    }
    (*qt_datas)--;
    if(*qt_datas == 0) {
        free(v_data);
        v_data = NULL;
    } else {
        Data *novo = realloc(v_data, (*qt_datas) * sizeof(Data));
        if(novo != NULL) v_data = novo;
    }
    printf("Data removida com sucesso!\n");
    return v_data;
}

// Editar data
void editar_data(Data *v_data, int qt_datas) {
    if(qt_datas == 0) {
        printf("Nenhuma data para editar.\n");
        return;
    }
    int idx = procurar_uma_data(v_data, qt_datas);
    if(idx == -1) {
        printf("Essa data não existe!\n");
        return;
    }
    printf("Editar data %d:\n", idx+1);
    printf("Novo dia: "); scanf("%d", &v_data[idx].dia);
    printf("Novo mês: "); scanf("%d", &v_data[idx].mes);
    printf("Novo ano: "); scanf("%d", &v_data[idx].ano);
    printf("Data editada com sucesso!\n");
}

// Ordenar por ano
void ordenar_por_ano(Data *v_data, int qt_datas) {
    if(qt_datas < 2) return;

    for(int i = 0; i < qt_datas - 1; i++) {
        for(int j = 0; j < qt_datas - i - 1; j++) {
            // Comparar ano, mês e dia
            int troca = 0;
            if(v_data[j].ano > v_data[j+1].ano) {
                troca = 1;
            } else if(v_data[j].ano == v_data[j+1].ano) {
                if(v_data[j].mes > v_data[j+1].mes) {
                    troca = 1;
                } else if(v_data[j].mes == v_data[j+1].mes) {
                    if(v_data[j].dia > v_data[j+1].dia) {
                        troca = 1;
                    }
                }
            }
            if(troca) {
                Data tmp = v_data[j];
                v_data[j] = v_data[j+1];
                v_data[j+1] = tmp;
            }
        }
    }

    printf("Datas ordenadas cronologicamente.\n");
}
