#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/**
 * Treinando com Estrutura de lista dinamica
 * referencia aula conceitual 8
 * 
 */
typedef struct no {
    int dado;
    struct no *proximo;
}no;

typedef no *ptr_no; //Para fazer alocação 

ptr_no lista;
int op;


//Prototipação
void menu_mostrar();
void menu_selecionar();
void lista_inserir(ptr_no lista);
void lista_remover(ptr_no lista);
void lista_mostrar(ptr_no lista);

/* Crie aqui o função main */
int main(){
    setlocale(LC_ALL, "Portuguese");
int op = 1;
lista = (ptr_no) malloc(sizeof(no)); // criando o primeiro no
lista->dado = 0;
lista->proximo = NULL;

//Laço Principal
while (op !=0){
    
    menu_mostrar();
    menu_selecionar();
    scanf("%d", &op);
}

getchar();
return 0;
}

//Função Mostrar o Menu Principal ("Menu de Opções")
void menu_mostrar(){
    lista_mostrar(lista);
    printf("\n\nEscolha uma das opções:\n");
    printf("1 - Inserir no final da Lista\n");
    printf("2 - Remover um item da Lista\n");
    printf("0 - Sair\n\n");
}

//Função para  Executar a opção escolhida no menu
 void menu_selecionar(){

    switch (op){
    case 1:
        lista_inserir(lista);
        break;
    case 2:
        lista_remover(lista);
        break;
    default:
        printf("Opção Inválida");
        break;
        
    }
}

//Função para inserir um elemento no final da Lista
void lista_inserir(ptr_no lista){
    while(lista->proximo != NULL){
        lista=lista->proximo;
    }
    lista->proximo = (ptr_no) malloc(sizeof(no));
    lista = lista->proximo;
    printf("\nDigite um elemento:");
    scanf("\n%d", &lista->dado);
    lista->proximo= NULL;
}

//Função para remover um elemento no final da Lista
void lista_remover(ptr_no lista){
    int elemento;
    ptr_no atual;
    atual = (ptr_no) malloc(sizeof(no));
    printf("\nEscolha um dos elementos para remover:\n");
    scanf("%d", &elemento);
    while((lista->dado != elemento)){
        if (lista->proximo == NULL){
            break;
        }
        atual = lista;
        lista = lista->proximo;
    }
    if (lista->dado == elemento){
        atual->proximo = lista->proximo;
    }
}

//Função Mostrar "Desenha o conteúdo da Lista na tela"
void lista_mostrar(ptr_no lista){
    system("clear");
    while(lista->proximo != NULL){
        printf("%d\t", lista->dado);
        lista = lista->proximo;
    }
    printf("%d\t", lista->dado);
}