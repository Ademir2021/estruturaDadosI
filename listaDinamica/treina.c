#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
 struct no {
     int dado;
     struct no *proximo;
 }no;
 typedef struct no *ptr_no;
 ptr_no lista;
 int op;

 //Prototipação
 void menu_mostrar();
 void lista_mostrar(ptr_no lista);
 void menu_selecionar(int op);
 void lista_inserir(ptr_no lista);
 void lista_remover(ptr_no lista);

 int main(){

     srand(time(NULL));
     op = 1;

     lista = (ptr_no) malloc(sizeof(no));
     lista->dado = 0;
     lista->proximo = NULL;

     while (op !=0 ){
         system("clear");
         menu_mostrar();
         scanf("%d", &op);
         menu_selecionar(op);
     }

     getchar();
     return 0;
 }

 //Mostra o menu de opções
 void menu_mostrar(){
     lista_mostrar(lista);
     printf("\n\nEscolha uma da Opções:\n");
     printf("1 - Inserir no Final da Lista\n");
     printf("2 - Remover um item da Lista\n");
     printf("0 - Sair\n\n");
 }

 //Executa a opção escolhida no menu
 void menu_selecionar(int op){
     switch (op)
     {
     case 1:
         lista_inserir(lista);
         break;
     
     case 2:
        lista_remover(lista);
         break;
     }
 }

 //Desenha o conteúdo na tela
 void lista_mostrar(ptr_no lista){
     system("clear");
     while(1){
         printf("%d, ", lista->dado);
         if(lista->proximo == NULL){
             break;
         }
         lista = lista->proximo;
     }
 }

 void lista_inserir(ptr_no lista){
     while(lista->proximo != NULL){
         lista = lista->proximo;
     }
     lista->proximo = (ptr_no) malloc(sizeof(no));
     lista = lista->proximo;
     lista->dado = rand()%100;
     lista->proximo = NULL;
 }

 void lista_remover(ptr_no lista){
     int dado;
     ptr_no atual;
     atual = (ptr_no) malloc (sizeof(no));
     printf("\nEscolha um dos itens:\n");
     scanf("%d", &dado);
     while((lista->dado != dado)){
         if (lista->proximo == NULL){
             break;
         }
         atual = lista;
         lista = lista->proximo;
     }
     if (lista->dado == dado){
         if(lista->dado == dado){
             atual->proximo = lista->proximo;
         }
     }
 }
