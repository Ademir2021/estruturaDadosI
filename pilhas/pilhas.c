#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define tamanho 5 //Constantes

struct tpilha { //Estrutura da Pilha
    int dados[tamanho];
    int ini;
    int fim;
};

struct tpilha pilha; //Variaveis Globais
int op;

void pilha_entrar(); //Protipação
void pilha_sair();
void pilha_mostrar();
void menu_mostrar();

int main () { //Função Principal
    setlocale(LC_ALL, "Portuguese");
    op = 1;
    pilha.ini = 0;
    pilha.fim = 0;
    while (op != 0) {
        system("clear");
        pilha_mostrar();
        menu_mostrar();
        scanf("%d", &op);
        switch (op) {
            case 1:
            pilha_entrar();
            break;
            case 2:
            pilha_sair();
            break;
        }
    }
    return (0);
}

void pilha_entrar() { //Adicionando um elemento no final da Pilha
    if (pilha.fim == tamanho) {
        printf("\nA pilha está cheia, impossivel empilhar!\n\n");
        getchar();
    }
    else {
        printf("\nDigite o valor a ser empilhado: ");
        scanf("%d,", &pilha.dados[pilha.fim]);
        pilha.fim++;
    }
}

void pilha_sair() { //Retirar o ultimo elemento da Pilha
    if (pilha.ini == pilha.fim) {
        printf("\n A pilha está vazia, impossível desempilhar!\n\n");
        getchar();
    }
    else {
        pilha.dados[pilha.fim-1] = 0;
        pilha.fim--;
    }
}

void pilha_mostrar() { //Mostrar o conteúdo da Pilha
    int i;
    printf("[ ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", pilha.dados[i]);
    }
    printf(" ]\n\n");
}

void menu_mostrar() { //Mostrar o menu de Opções
    printf("\nEscolha uma opção:\n");
    printf("1 - Empilhar\n");
    printf("2 - Desempilhar\n");
    printf("0 - Sair\n\n");
}