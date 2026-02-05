#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char nome[50];
    char telefone[20];
} Contato;

void inserir(Contato **contato, int *cont) {
    Contato cTemp;
    printf("Nome: ");
    scanf(" %49[^\n]", cTemp.nome);
    printf("Telefone: ");
    scanf(" %19[^\n]", cTemp.telefone);

    for (int i = 0; i < *cont; i++) {
        if (strcmp(cTemp.nome, (*contato)[i].nome) == 0) {
            printf("Nome já existe, não pode ser adicionado\n");
            return;
        }
    }

    Contato *temp = realloc(*contato, (*cont + 1) * sizeof(Contato));
    if (temp == NULL) {
        printf("Erro de memória\n");
        return;
    }

    *contato = temp;
    (*contato)[*cont] = cTemp;
    (*cont)++;
}

void listar(Contato *contato, int cont) {
    Contato temp;
    for (int i = 0; i < cont - 1; i++) {
        for (int j = 0; j < cont - 1; j++) {
            if (strcmp(contato[j].nome, contato[j + 1].nome) > 0) {
                temp = contato[j];
                contato[j] = contato[j + 1];
                contato[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < cont; i++) {
        printf("Nome: %s\nTelefone: %s\n\n", contato[i].nome, contato[i].telefone);
    }
}

void buscar(Contato *contato, int cont) {
    bool existe = false;
    char nome[50];
    printf("Buscar: ");
    scanf(" %49[^\n]", nome);

    for (int i = 0; i < cont; i++) {
        if (strcmp(contato[i].nome, nome) == 0) {
            printf("Nome: %s\nTelefone: %s\n\n", contato[i].nome, contato[i].telefone);
            existe = true;
            break;
        }
    }

    if (!existe)
        printf("Contato não encontrado.\n");
}

int menu() {
    int op;
    printf("(1) Inserir Contato\n"
           "(2) Listar contato\n"
           "(3) Buscar Contato por nome\n"
           "(4) Sair\n");
    scanf("%d", &op);
    return op;
}

int main() {
    Contato *contato = NULL;
    int op = 0, cont = 0;

    do {
        printf("\nMenu de contatos\n");
        op = menu();
        switch (op) {
            case 1: inserir(&contato, &cont); break;
            case 2: listar(contato, cont); break;
            case 3: buscar(contato, cont); break;
        }
    } while (op != 4);

    free(contato);
    printf("\nFIM\n");
    return 0;
}
