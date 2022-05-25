#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

typedef struct no{
    int dado;
    struct no *proximo;
}no;

typedef no *ptr_no;
ptr_no pilha;
int op;

void pilha_Inserir(ptr_no pilha);
void pilha_Mostrar(ptr_no pilha);

int main(){
    setlocale(LC_ALL, "Portuguese");

    srand(time(NULL));
    op = 1;
    pilha = (ptr_no) malloc(sizeof(no));
    pilha->dado = 0;
    pilha->proximo = NULL;

    pilha_Inserir(pilha);
    pilha_Mostrar(pilha);


    getchar();
    return 0;
}

void pilha_Inserir(ptr_no pilha){
    while(pilha->proximo != NULL){
        pilha = pilha->proximo;
    }
    pilha->proximo = (ptr_no) malloc(sizeof(no));
    pilha = pilha->proximo;
    pilha->dado = rand()%100;
    pilha->proximo = NULL;
}

void pilha_Mostrar(ptr_no pilha){
    system("clear");
    while(pilha->proximo != NULL){
        printf("%d, ", pilha->dado);
        pilha = pilha->proximo;
    }
    printf("%d, ", pilha->dado);
}