#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

void menu()
{
    printf("1 - Adicionar produto\n"
           "2 - Listar produtos\n"
           "3 - Atualizar stock\n"
           "4 - Remover produto\n"
           "5 - Sair  \n");
} // aqui estou recebendo o endereco de memoria do produto e do contM
void adicionar_produto(Produto **produto, int *contM, int *id)
{

    // criando um produto temporario
    Produto temp;
    // adicionando no produto temporario

    printf("Nome Produto: ");
    scanf(" %49[^\n]", temp.nome);
    for (int i = 0; i < *contM; i++)
    {

        if (strcmp(temp.nome, ((*produto)[i].nome)) == 0)
        {
            printf("Nome ja existe, nao pode adciconar");
            return;
        }
    }

    printf("Quantidade: ");
    scanf("%d", &temp.quantidade);
    if (temp.quantidade < 0)
    {
        printf("numero negativo ");
        return;
    }
    printf("Preco: ");
    scanf("%f", &temp.preco);
    if (temp.preco <= 0)
    {
        printf("O preco tem que ser maior que 0 ");
        return;
    }
    // criando um produto temporario *tempProduto - adicionando um espaco na memoria
    Produto *tempProduto = realloc(*produto, (*contM + 1) * sizeof(Produto));
    // verificando se o endereco de memoria esta vazil
    if (tempProduto == NULL)
    {
        printf("erro de memoria");
        return;
    }
    *produto = tempProduto;
    temp.id = (*id)++;
    (*produto)[*contM] = temp;
    (*contM)++;
}
void listar_produtos(Produto *produto, int contM)
{
    if (contM == 0)
    {
        printf("Nenhuma produto cadastrada.\n");
        return;
    }
    for (int i = 0; i < contM; i++)
    {

        printf("%-10d| %-10s|%-5d|%.2f\n", produto[i].id, produto[i].nome, produto[i].quantidade,produto[i].preco);
    }
}
void atualizar_stock(Produto *produto, int contM)
{
    int x = 0;
    int encontrado = 0;
    listar_produtos(produto, contM);
    printf("Qual produto deseja alterar: ");
    scanf("%d", &x);
    for (int i = 0; i < contM; i++)
    {
        if (produto[i].id == x)
        {
            printf("Nova quantidade:\n");
            scanf("%d", &produto[i].quantidade);
            printf("Quantidade atualizada\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado)
    {
        printf("Produto não encontrado.\n");
    }
}

void remover_produto(Produto **produto, int *contM)
{
    int x = 0;
    int cont = 0;
    int encontrado = 0;
    listar_produtos(*produto, *contM);
    printf("Qual produto quer excluir");
    scanf("%d", &x);
    for (int i = 0; i < *contM; i++)
    {
        if ((*produto)[i].id != x)
        {
            (*produto)[cont] = (*produto)[i];
            cont++;
        }
        else
        {
            encontrado = 1; // marca que encontrou
        }
    }
    if (!encontrado)
    {
        printf("Produto não encontrado.\n");
        return;
    }
    *contM = cont;
    if (*contM > 0)
    {
        Produto *temp = realloc(*produto, (*contM) * sizeof(Produto));
        if (temp == NULL)
        {
            printf("Erro de memória.\n");
            return;
        }
        *produto = temp;
    }
    else
    {
        free(*produto);
        *produto = NULL;
    }
    printf("Produto removido com sucesso.\n");
}
int main()
{
    Produto *produto = NULL;
    int op = 0, id = 0;
    int contM = 0;
    do
    {
        menu();
        if (scanf("%d", &op) != 1)
{
    printf("Entrada inválida.\n");
    return 0;
}
        switch (op)
        {
        case 1:
            adicionar_produto(&produto, &contM, &id);
            break;
        case 2:
            listar_produtos(produto, contM);
            break;
        case 3:
            atualizar_stock(produto, contM);
            break;
        case 4:
            remover_produto(&produto, &contM);
            break;
        case 5:
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }

    } while (op != 5);
    free(produto);
    return 0;
}
