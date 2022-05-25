#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Definindo a estrutura da fila
struct no {
    int dado;
    struct no *proximo;
}no;
typedef struct no *ptr_no;
ptr_no fila;
int op;
//Prototipação
void menu_mostrar();
void menu_selecionar(int op);
void fila_inserir(ptr_no fila);
void fila_remover(ptr_no fila);
void fila_mostrar(ptr_no fila);
//Função principal
int main() {
    //Iniciando a máquina de números randomicos
    srand(time(NULL));
    op = 1;
    //Criando o primeiro no da fila
    fila = (ptr_no) malloc(sizeof(no));
    fila->dado = 0;
    fila->proximo = NULL;
    //Laço principal
    while (op !=0) {
        system("clear");
        menu_mostrar();
        scanf("%d", &op);
        menu_selecionar(op);
    }
    getchar();
    return(0);
}
//Mostra o menu de opções
void menu_mostrar() {
    fila_mostrar(fila);
    printf("\nEscolha uma das opções:\n");
    printf("1 - inserir no final da fila\n");
    printf("2 - Remove no inicio da fila\n");
    printf("0 - Sair\n\n");
}
//Executa a opção escolhida no menu
void menu_selecionar(int op) {
    switch(op) {
        case 1:
        fila_inserir(fila);
        break;
        case 2:
        fila_remover(fila);
        break;
    }
}
//Insere um elemento no final da fila
void fila_inserir(ptr_no fila) {
    while(fila->proximo !=NULL) {
        fila = fila->proximo;
    }
    fila->proximo = (ptr_no) malloc(sizeof(no));
    fila = fila->proximo;
    fila->dado = rand()%100;
    fila->proximo = NULL;
}
//Remove um elemento do inicio da fila
void fila_remover(ptr_no fila) {
    ptr_no atual;
    atual = (ptr_no) malloc(sizeof(no));
    atual = fila;
    if(fila->proximo !=NULL){
        fila = fila->proximo;
    atual->proximo = fila->proximo;
    }
}


//Desenha o conteudo da fila na tela
void fila_mostrar(ptr_no fila) {
    system("clear");
    while(fila->proximo != NULL) {
        printf("%d, ", fila->dado);
        fila = fila->proximo;
    }
    printf("%d, ", fila->dado);
}
