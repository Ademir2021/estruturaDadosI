#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 8

typedef struct str_no {
    int id;
    struct str_no *proximo;
}str_no;

struct str_no grafo[MAXV];


//int main() {}

void buscaEmProfundidade(struct str_no g[], int inicio, int alvo) {
    int pilha[MAXV]; //pilha
    bool visitado[MAXV]; //nós visitados
    int indice = 0; //indice do topo da pilha
    bool achou = false; //flag de controle (não visitados)
    int corrente = inicio;
    struct str_no *ptr;
    int i;
    printf("=-=-=-= Busca em Profundidade =-=-=-=\n");
    //Marcando os nós não visitados
    for(i=0; i< MAXV; i++) {
        visitado[i] = false;
    }
    while(true) {
        //No corrente não visitado? Marque como visitado,
        //Empilhe o nó corrente,
        if(!visitado[corrente]) {
            printf("VISITADO: %d, \n", corrente);
            if(corrente == alvo)
            {
                printf("Alvo encontrado!\n\n\n");
                return;
            }
            visitado[corrente] = true;
            pilha[indice] = corrente;
            indice++;
        }
        //Buscando por nós adjacentes, não visitado.
        achou = false;
        for(ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo) {
            if(!visitado[ptr->id]) {
                achou = true;
                break;
            }
        }
        if (achou) {
            //Atualizando o nó corrente
            corrente = ptr->id;
        }
        else{
            //Não há vértices adjacentes não visitados
            //tentando desempilharo vertice do topo.
            indice--;
            if(indice == -1) {
                //Não há mais vertices não empilhados.
                printf("Encerrando a busca. \n");
                break;
            }
            corrente = pilha[indice -1];
        }
    }
   return;
}



