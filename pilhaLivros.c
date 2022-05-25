#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define tamanho  5

struct tlivro {
    int codigo;
    char nome[50];
    char autor[50];
};

struct tpilha {
    struct tlivro dados[tamanho];
    int ini;
    int fim;
};

struct tpilha pilha;
int op;

void menu_mostrar();
void menu_selecionar(int op);
void pilha_entrar();
void pilha_mostrar();

/* função main */
int main(){
    setlocale(LC_ALL, "Portuguese");

    op = 1;

    while(op !=0 ){
    system("clear");
    menu_mostrar();
    scanf("%d", &op);
    menu_selecionar(op);
    }

  getchar();
  return (0);
}

void menu_mostrar() {
    pilha_mostrar();
    printf("\nDigite sua opção !\n");
    printf("1 - Empilhar Livro\n");
    printf("0 - Sair\n\n");
}

void menu_selecionar(int op){
    switch (op)
    {
    case 1:
        pilha_entrar();
        break;
    case 2:
        //pilha_sair();
        break;
    default:
        printf("opção inválida");
        break;
    }
}

void pilha_entrar() {

    if (pilha.fim == tamanho) {
        printf("\n A pilha está cheia, impossivel empilhar!\n\n");
        getchar();
    }
    else {
        printf("\nDigite o código do livro: ");
        scanf("%d", &pilha.dados[pilha.fim].codigo);
        printf("\nDigite o nome do livro: ");
        scanf("%s", pilha.dados[pilha.fim].nome);
        printf("\nDigite o autor do livro: ");
        scanf("%s", pilha.dados[pilha.fim].autor);
        pilha.fim++;  
}
op++;
}

void pilha_mostrar() {
    int i;
    printf("[ \n");
    for (i=0; i < pilha.fim; i++) {
        printf("Codigo:%d Nome:%s Autor:%s\n", pilha.dados[i].codigo, pilha.dados[i].nome, pilha.dados[i].autor);
    }
    printf("]\n\n");
}