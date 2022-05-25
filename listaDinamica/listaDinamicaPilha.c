#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Definindo a estrutuda da pilha
typedef struct no { //Aqui o typedef parece ser opcional!?
    int dado;
    struct no *proximo;
}no;

//Definindo variaveis
typedef struct no *ptr_no;
ptr_no pilha;
int op;

//Prototipação
void menu_mostrar();
void menu_selecionar();
void pilha_inserir(ptr_no pilha);
void pilha_remover(ptr_no pilha);
void pilha_mostrar(ptr_no pilha);

/**
 * Autor: Ademir Souza de Almeida
 * Função Principal
 */
int main() {
//inicializando a máquina de numero randômicos
srand(time(NULL));
op = 1;
//criando o primeiro no da pilha
//Laço principal
while(op !=0) {
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
    pilha_mostrar(pilha);
    printf("\nEscolha uma da opções:\n");
    printf("1 - Inserir no final da pilha\n");
    printf("2 - Remover no final da pilha\n");
    printf("0 - Sair\n\n");
    }

//Executa a opção escolhida no menu
void menu_selecionar(int op) {
    switch (op) {
        case 1:
        pilha_inserir(pilha);
        break;
        case 2:
        pilha_remover(pilha);
        break;
    }    
}

//insere um elemento no final da pilha
void pilha_inserir(ptr_no pilha) {
while(pilha->proximo != NULL){
pilha = pilha->proximo;
}
pilha->proximo = (ptr_no) malloc(sizeof(no));
pilha = pilha->proximo;
pilha->dado = rand()%100;
pilha->proximo = NULL;
}

//Remove um elemento da pilha
void pilha_remover(ptr_no pilha) {
    ptr_no atual;
    atual = (ptr_no) malloc(sizeof(no));
    while(pilha->proximo !=NULL) {
        atual = pilha;
        pilha = pilha->proximo;
    }
    atual->proximo = NULL;
}

//Desenha o conteúdo da pilha na tela
void pilha_mostrar(ptr_no pilha) {
    system("clear");
    while(pilha->proximo !=NULL) {
        printf("%d ",pilha->dado);
        pilha = pilha->proximo;
}
printf("%d, ", pilha->dado);
}