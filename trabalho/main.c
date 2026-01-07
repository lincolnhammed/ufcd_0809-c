#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXTO 60

typedef struct {
    int id;
    char nome[MAX_TEXTO];
    char apelido[MAX_TEXTO];
    int idade;
    char funcao[MAX_TEXTO];
    char dataNascimento[11]; // "DD/MM/AAAA" -> 10 + '\0'
    double salario;          // campo extra escolhido
} Funcionario;

static void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static void lerLinha(char *destino, int tamanho) {
    if (fgets(destino, tamanho, stdin) == NULL) {
        destino[0] = '\0';
        return;
    }
    // remover '\n' final, se existir
    destino[strcspn(destino, "\n")] = '\0';
}

static int lerInt(const char *msg) {
    int v;
    for (;;) {
        printf("%s", msg);
        if (scanf("%d", &v) == 1) {
            limparBuffer();
            return v;
        }
        printf("Entrada inválida. Tenta novamente.\n");
        limparBuffer();
    }
}

static double lerDouble(const char *msg) {
    double v;
    for (;;) {
        printf("%s", msg);
        if (scanf("%lf", &v) == 1) {
            limparBuffer();
            return v;
        }
        printf("Entrada inválida. Tenta novamente.\n");
        limparBuffer();
    }
}

static int encontrarIndicePorID(const Funcionario *lista, int total, int id) {
    // procura linear (suficiente para trabalhos deste tipo)
    for (int i = 0; i < total; i++) {
        if (lista[i].id == id) return i;
    }
    return -1;
}

static void imprimirFuncionario(const Funcionario *f) {
    printf("ID:%d | %s %s | Idade:%d | Função:%s | Nasc:%s | Salário:%.2f\n",
           f->id, f->nome, f->apelido, f->idade, f->funcao, f->dataNascimento, f->salario);
}

static void inserirFuncionario(Funcionario **lista, int *total, int *capacidade) {
    if (*total == *capacidade) {
        int novaCap = (*capacidade == 0) ? 4 : (*capacidade * 2);
        Funcionario *tmp = (Funcionario*)realloc(*lista, novaCap * sizeof(Funcionario));
        if (!tmp) {
            printf("Erro: sem memória.\n");
            return;
        }
        *lista = tmp;
        *capacidade = novaCap;
    }

    Funcionario f;

    // garantir ID único
    for (;;) {
        f.id = lerInt("ID do funcionário (inteiro): ");
        if (encontrarIndicePorID(*lista, *total, f.id) == -1) break;
        printf("Já existe um funcionário com esse ID. Escolhe outro.\n");
    }

    printf("Nome: ");
    lerLinha(f.nome, MAX_TEXTO);

    printf("Apelido: ");
    lerLinha(f.apelido, MAX_TEXTO);

    f.idade = lerInt("Idade: ");

    printf("Função: ");
    lerLinha(f.funcao, MAX_TEXTO);

    printf("Data de nascimento (DD/MM/AAAA): ");
    lerLinha(f.dataNascimento, 11);

    f.salario = lerDouble("Salário (campo extra): ");

    (*lista)[*total] = f;
    (*total)++;

    printf("Funcionário inserido com sucesso.\n");
}

static int cmpID(const void *a, const void *b) {
    const Funcionario *fa = (const Funcionario*)a;
    const Funcionario *fb = (const Funcionario*)b;
    return (fa->id > fb->id) - (fa->id < fb->id);
}

static int cmpNome(const void *a, const void *b) {
    const Funcionario *fa = (const Funcionario*)a;
    const Funcionario *fb = (const Funcionario*)b;

    int r = strcmp(fa->nome, fb->nome);
    if (r != 0) return r;
    // desempate por apelido e por ID para ficar estável e previsível
    r = strcmp(fa->apelido, fb->apelido);
    if (r != 0) return r;
    return (fa->id > fb->id) - (fa->id < fb->id);
}

static void listarOrdemInsercao(const Funcionario *lista, int total) {
    if (total == 0) {
        printf("Sem funcionários.\n");
        return;
    }
    for (int i = 0; i < total; i++) {
        imprimirFuncionario(&lista[i]);
    }
}

static void listarOrdenado(const Funcionario *lista, int total, int porNome) {
    if (total == 0) {
        printf("Sem funcionários.\n");
        return;
    }

    // para não destruir a ordem de inserção, copiamos e ordenamos a cópia
    Funcionario *copia = (Funcionario*)malloc(total * sizeof(Funcionario));
    if (!copia) {
        printf("Erro: sem memória.\n");
        return;
    }
    memcpy(copia, lista, total * sizeof(Funcionario));

    if (porNome) qsort(copia, total, sizeof(Funcionario), cmpNome);
    else qsort(copia, total, sizeof(Funcionario), cmpID);

    for (int i = 0; i < total; i++) {
        imprimirFuncionario(&copia[i]);
    }

    free(copia);
}

static void apagarFuncionario(Funcionario *lista, int *total) {
    if (*total == 0) {
        printf("Sem funcionários.\n");
        return;
    }

    int id = lerInt("ID a apagar: ");
    int idx = encontrarIndicePorID(lista, *total, id);

    if (idx == -1) {
        printf("Não existe funcionário com esse ID.\n");
        return;
    }

    // remover mantendo ordem de inserção: “puxar” elementos para a esquerda
    for (int i = idx; i < *total - 1; i++) {
        lista[i] = lista[i + 1];
    }
    (*total)--;

    printf("Funcionário apagado.\n");
}

static void atualizarFuncionario(Funcionario *lista, int total) {
    if (total == 0) {
        printf("Sem funcionários.\n");
        return;
    }

    int id = lerInt("ID a atualizar: ");
    int idx = encontrarIndicePorID(lista, total, id);

    if (idx == -1) {
        printf("Não existe funcionário com esse ID.\n");
        return;
    }

    Funcionario *f = &lista[idx];

    printf("Atualizar funcionário (ENTER para manter valor atual)\n");

    printf("Nome atual: %s\nNovo nome: ", f->nome);
    char tmp[MAX_TEXTO];
    lerLinha(tmp, MAX_TEXTO);
    if (tmp[0] != '\0') strncpy(f->nome, tmp, MAX_TEXTO);

    printf("Apelido atual: %s\nNovo apelido: ", f->apelido);
    lerLinha(tmp, MAX_TEXTO);
    if (tmp[0] != '\0') strncpy(f->apelido, tmp, MAX_TEXTO);

    printf("Idade atual: %d\nNova idade (ou -1 para manter): ", f->idade);
    int novaIdade;
    if (scanf("%d", &novaIdade) == 1) {
        limparBuffer();
        if (novaIdade >= 0) f->idade = novaIdade;
    } else {
        limparBuffer();
    }

    printf("Função atual: %s\nNova função: ", f->funcao);
    lerLinha(tmp, MAX_TEXTO);
    if (tmp[0] != '\0') strncpy(f->funcao, tmp, MAX_TEXTO);

    printf("Data nasc. atual: %s\nNova data (DD/MM/AAAA): ", f->dataNascimento);
    char tmpData[11];
    lerLinha(tmpData, 11);
    if (tmpData[0] != '\0') strncpy(f->dataNascimento, tmpData, 11);

    printf("Salário atual: %.2f\nNovo salário (ou -1 para manter): ", f->salario);
    double novoSal;
    if (scanf("%lf", &novoSal) == 1) {
        limparBuffer();
        if (novoSal >= 0) f->salario = novoSal;
    } else {
        limparBuffer();
    }

    printf("Funcionário atualizado.\n");
}

static void menu(void) {
    printf("\n==== MENU ====\n");
    printf("1. Inserir funcionário\n");
    printf("2. Listar funcionários ordenados por ID\n");
    printf("3. Listar funcionários ordenados por nome\n");
    printf("4. Listar funcionários por ordem de inserção\n");
    printf("5. Apagar funcionário (por ID)\n");
    printf("6. Atualizar funcionário (por ID)\n");
    printf("7. Sair\n");
}

int main(void) {
    Funcionario *lista = NULL;
    int total = 0;
    int capacidade = 0;

    for (;;) {
        menu();
        int op = lerInt("Escolha uma opção: ");

        if (op == 1) inserirFuncionario(&lista, &total, &capacidade);
        else if (op == 2) listarOrdenado(lista, total, 0);
        else if (op == 3) listarOrdenado(lista, total, 1);
        else if (op == 4) listarOrdemInsercao(lista, total);
        else if (op == 5) apagarFuncionario(lista, &total);
        else if (op == 6) atualizarFuncionario(lista, total);
        else if (op == 7) break;
        else printf("Opção inválida.\n");
    }

    free(lista);
    printf("Programa terminado.\n");
    return 0;
}
