#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no { //Define a estrutura da Lista
    int dado;
    struct no *proximo;
}no;

typedef struct no  *ptr_no; //Definindo 

ptr_no lista;
int op;

void menu_mostrar(); //Prototipação
void menu_selecionar(int op);
void lista_inserir(ptr_no lista);
void lista_remover(ptr_no lista);
void lista_mostrar(ptr_no lista);

int main() { //função principal

    srand(time(NULL)); //Inicializando máquina de números randômicos
    op = 1;
    lista = (ptr_no) malloc(sizeof(no)); //Criando o Primeiro no da Lista
    lista->dado = 0;
    lista->proximo = NULL;

    while (op !=0) { //Laço principal
        system("clear");
        menu_mostrar();
        scanf("%d", &op);
        menu_selecionar(op);
    }
    getchar();
    return(0);
}

void menu_mostrar() { //Mostra o menu de opções
    lista_mostrar(lista);
    printf("\nEscolha uma das opções:\n");
    printf("1 - Inserir no final da pilha\n");
    printf("2 - Remover no final da pilha\n");
    printf("0 - Sair\n\n");
}

void menu_selecionar(int op) { //Executa a opção escolhida no menu
    switch (op) {
        case 1:
        lista_inserir(lista);
        break;
        case 2:
        lista_remover(lista);
        break;
    }
}

void lista_inserir(ptr_no lista) { //Insere um elemento no final da Lista
    while(lista->proximo != NULL) {
        lista = lista->proximo;
    }
    lista->proximo = (ptr_no) malloc(sizeof(no));
    lista = lista->proximo;
    lista->dado = rand()%100;
    lista->proximo = NULL;
}

void lista_remover(ptr_no lista) { //Remove um elemento da Lista
    int dado;
    ptr_no atual;
    atual = (ptr_no) malloc(sizeof(no));
    printf("\n\nEscolha uma dos itens:\n");
    scanf("%d", &dado);
    while((lista->dado != dado)) {
        if (lista->proximo == NULL) {
            break;
        }
        atual = lista;
        lista = lista->proximo;
    }
    if(lista->dado == dado) {
        atual->proximo = lista->proximo;
    }
}

void lista_mostrar(ptr_no lista) { //Desenha o elemento da Lista na Tela
    system("clear");
    while(lista->proximo !=NULL) {
        printf("%d\t", lista->dado);
        lista = lista->proximo;
    }
    printf("%d\t", lista->dado);  
}