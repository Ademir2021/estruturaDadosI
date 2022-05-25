#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tamanho 5 //Constante

struct tfila { //Estrutura da Fila
    int dados[tamanho];
    int ini;
    int fim;
}; struct tfila fila; int op; //Variaveis Globais

void fila_entrar(); //Protipação
void fila_sair();
void fila_mostrar();
void menu_mostrar();

int main() { //Função Principal
    setlocale(LC_ALL, "Portuguese");
    op = 1;
    fila.ini = 0;
    fila.fim = 0;
    while(op != 0 ) {
        system("clear");
        fila_mostrar();
        menu_mostrar();
        scanf("%d", &op);
        switch (op) {
            case 1:
            fila_entrar();
            break;
            case 2:
            fila_sair();
            break;
        }
    }
    return(0);
}

void fila_entrar() { //Adiciona um elemento ao final da fila
    if (fila.fim == tamanho) {
        printf("\nA Fila está cheia, volte outro dia!\n\n");
        system("pause");
    }
    else {
        printf("\nDigite um valor a ser inserido: ");
        scanf("%d", &fila.dados[fila.fim]);
        fila.fim++;
    }
}

void fila_sair() { //Retirar o primeiro elemento da Fila
    if (fila.ini == fila.fim){
        printf("\nFila vazia, mas logo aparece alguém!\n\n");
        system("pause");
    }
    else {
        for (int i = 0; i < tamanho; i++) {
            fila.dados[i] = fila.dados[i+1];
            }
            fila.dados[fila.fim] = 0;
            fila.fim--;
            }
    }

void fila_mostrar() { //Mostrar o conteudo da fila
    int i;
    printf("[ ");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", fila.dados[i]);
    }
    printf("]\n\n");
}

void menu_mostrar() { //Mostrar o menu de opções
    printf("\nEscolha uma opção:\n");
    printf("1 - Incluir na Fila\n");
    printf("2 Excluir na Fila\n");
    printf("0 Sair\n\n");
}