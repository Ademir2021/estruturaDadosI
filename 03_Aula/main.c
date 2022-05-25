#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct dl_elementoLista{
  char *dado;
  struct dl_elementoLista *anterior;
  struct dl_elementoLista *proximo;
}dl_elemento;

typedef struct dl_ListaDetectada{
  dl_elemento *inicio;
  dl_elemento *fim;
  int tamanho;
}dl_Lista;

int ins_vazia(dl_Lista *lista, char *data){
  dl_elemento *novo;
  if ((novo = malloc(sizeof(novo)) == NULL)){
    return -1;
  }
  strcpy(novo->dado, data);
  novo->anterior = NULL;
  novo->proximo = NULL;
  lista->inicio = novo;
  lista->fim = novo;
  lista->tamanho++;
  return 0;
}

int ins_inicio(dl_Lista *lista, char *data){
  dl_elemento *novo;
  if ((novo = malloc(sizeof(novo)) == NULL)){
    return -1;
  }
  strcpy(novo->dado, data);
  novo->anterior = NULL;
  novo->proximo = lista->inicio;
  lista->inicio = novo;
  lista->tamanho++;
  return 0;
}

int ins_final(dl_Lista *lista, char *data){
  dl_elemento *novo;
  if ((novo = malloc(sizeof(novo)) == NULL)){
    return -1;
  }
  strcpy(novo->dado, data);
  novo->proximo = NULL;
  novo->anterior = lista->fim;
  lista->fim->proximo = novo;
  lista->fim = novo;
  lista->tamanho++;
  return 0;
}

int main(void) {
  printf("Hello World\n");
  return 0;
}