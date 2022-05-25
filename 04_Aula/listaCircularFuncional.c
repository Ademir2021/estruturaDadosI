#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

  struct LISTA{
    int num;
    struct LISTA *prox;
    struct LISTA *ant;  
  };
  struct LISTA *inicio = NULL;
  struct LISTA *fim = NULL;
  struct LISTA *aux;

   int op, numero, achou;

  //Prototipação
  void menu_mostrar(void);
  void ini_lista(void);
  void fim_lista(void);
  void consulta_lista_ini(void);
  void consulta_lista_fim(void);
  void remove_lista(void);
  void esvazia_lista(void);

int main() {
  setlocale (LC_ALL, "Portuguese");

  do{
    menu_mostrar();
    ini_lista();
    fim_lista();
    consulta_lista_ini();
    consulta_lista_fim();
    remove_lista();
    esvazia_lista();
    
  getchar();   
  }
 while (op!= 7);
}

void menu_mostrar(){
  system("clear");
    printf("\nMENU DE OPÇÕES\n");
    printf("\n1 - Inserir no início da lista");
    printf("\n2 - Inserir no fim da lista");
    printf("\n3 - Consultar a lista do início ao fim");
    printf("\n4 - Consultar a lista do fim ao início");
    printf("\n5 - Remover da lista");
    printf("\n6 - Esvaziar a lista");
    printf("\n7 - Sair");
    printf("\nDigite sua opção: ");
    scanf("%d", &op);
    if (op < 1 || op > 7)
      printf("Opção inválida!!");
}

void ini_lista(){
  if (op == 1){
      printf("Digite o número a ser inserido no início da lista: ");
      struct LISTA *novo = malloc(sizeof(struct LISTA));
      scanf("%d", &novo->num);
      if (inicio == NULL){
        inicio = novo;
        fim = novo;
        novo->prox = inicio;
        novo->ant = inicio;
      }else{
        novo->prox = inicio;
        inicio->ant = novo;
        novo->ant = fim;
        fim->prox = novo;
        inicio=novo;
      }
      printf("Número inserido no início da lista.");
    }
}

void fim_lista(void){
  if (op == 2){
      printf("Digite o número a ser inserido no fim da lista: ");
      struct LISTA *novo = malloc(sizeof(struct LISTA));
      scanf("%d", &novo->num);
      if (inicio == NULL){
        inicio = novo;
        fim = novo;
        novo->prox = inicio;
        novo->ant = inicio;
      }else{        
        fim->prox = novo;
        novo->ant = fim;        
        fim=novo;
        fim->prox = inicio;
        inicio->ant = fim;
      }
      printf("Número inserido no fim da lista.");
    }
}

void consulta_lista_ini(void){
      if (op == 3){
      if (inicio == NULL){
        printf("Lista vazia!!");
      }else{
        printf("\nConsultando a lista do início ao fim\n");
        aux = inicio;
        do{
          printf("%d", aux->num);
          aux = aux->prox;
        }
        while (aux != inicio);
      }
    }
}

void consulta_lista_fim(){
  if (op == 4){
      if (inicio == NULL){
        printf("Lista vazia!!");
      }else{
        printf("\nConsultando a lista do fim ao fim\n");
        aux = fim;
        do{
          printf("%d", aux->num);
          aux = aux->ant;
        }
        while (aux != fim);
      }
    }
}

void remove_lista(void){
  if (op == 5){
       if (inicio == NULL){
        printf("Lista vazia!!");
      }else{
         printf("\nDigite o elemento a ser removido: ");
         scanf("%d", &numero);
         aux = inicio;
         achou = 0;
         int quantidade = 0;
         aux = inicio;
         do{
           quantidade++;
           aux = aux->prox;
         }while (aux != inicio);
         int elemento = 1;
         do{
           if (inicio == fim && inicio->num == numero){
             inicio = NULL;
             free(inicio);
             achou++;
           }else{
             if (aux->num == numero){
               achou++;
               if (aux == inicio){
                 inicio = aux->prox;
                 inicio->ant = fim;
                 fim->prox = inicio;
                 free(aux);
                 aux = inicio;
               }else if(aux == fim){
                 fim = fim->ant;
                 fim->prox = inicio;
                 inicio->ant = fim;
                 free(aux);
                 aux = NULL;
               }else{
                 aux->ant->prox = aux->prox;
                 aux->prox->ant = aux->ant;
                 struct LISTA *aux2;
                 aux2 = aux;
                 aux = aux->prox;
                 free(aux2);
               }
             }else{
               aux = aux->prox;
             }
           }
           elemento++;
         }while(elemento <= quantidade);
         if (achou == 0)
           printf("Número não encontrado");
         else if (achou == 1)
           printf("Número removido 1 vez");
         else
           printf("Número removido %d vezes", achou);
         }
      }
}

void esvazia_lista(void){
   if (op == 6){
      if (inicio == NULL){
        printf("Lista vazia!!");
      }else{
        aux = inicio;
        do{
          inicio = inicio->prox;
          free(aux);
          aux = inicio;
        }while (aux != fim);
        free(fim);
        inicio = NULL;
        printf("Lista esvaziada.");
      }
    }
}