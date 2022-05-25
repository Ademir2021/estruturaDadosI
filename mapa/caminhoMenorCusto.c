#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Variáveis
int destino, origem, vertices = 0;
float custo, *custos = NULL;

//Prototipação
void dijkstra(int vertices, int origem, int destinho, float *custos);
void menu_mostrar(void);
void grafo_procurar(void);
void grafo_criar(void);

//Função Principal
int main(int argc, char **argv){

    int opt = -1;
    //Laço principal do menu
    do {
        //Desenha o menu na tela
        menu_mostrar();
        scanf("%d", &opt);
        switch(opt){
            case 1:
                grafo_criar();
                break;
            case 2:
            if (vertices > 0){
                grafo_procurar();
            }
                break;
        }
    }while(opt !=0);
    printf("\nAlgoritmo de Dijkstra finalizado...\n\n");
    getchar();
    return 0;
}


//Implementação do algoritmo de Dijkstra
void dijkstra(int vertices, int origem, int destino, float *custos)
{
    int i, v, cont = 0;
    int *ant, *tmp;
    int *z; /* vertices para os quais se conhece o caminho minimo */
    double min;
    double dist[vertices]; /* vetor com os custos dos caminhos */
    /* aloca as linhas da matriz*/
    ant = (int*) calloc (vertices, sizeof(int *));
    if (ant == NULL){
        system("color fc");
        printf("** Erro: Mémoria Insuficiente **");
        exit(-1);
    }
    tmp = (int*) calloc (vertices, sizeof(int *));
    if (tmp == NULL){
        //system ("color fc");
        printf("** Erro: Mémoria Insulficiente **");
        exit(-1);
    }
    z = (int*) calloc (vertices, sizeof(int *));
    if (z == NULL){
        //system("color fc");
        printf("** Erro Mémoria Insulficiente **");
        exit (-1);
    }
    for (i = 0; i < vertices; i++){
        if (custos[(origem - 1) * vertices + i] !=- 1){
            ant[i] = origem -1;
            dist[i] = custos[(origem -1)*vertices+i];
        }
        else{
            ant[i]= -1;
            dist[i] = HUGE_VAL;
        }
        z[i]=0;
    }
    z[origem -1] = 1;
    dist[origem-1] = 0;
    /*Laço principal*/
    do {
        /* Encontrando o vertice que deve entrar em z */
        min = HUGE_VAL;
        for (i=0; i<vertices; i++){
            if (!z[i]){
                if (dist[i]>=0 && dist[i]<min){
                    min=dist[i];v=i;
                }
            }
        }
        /* Calculando as distancias dos novo vizinho de z */
        if (min != HUGE_VAL && v != destino -1){
            z[v] = 1;
            for (i = 0; i < vertices; i++){
                if (!z[i]){
                    if (custos[v*vertices+i] != -1 && dist[v] + custos[v*vertices+i] < dist[i]) {
                        dist[i] = dist[v] + custos[v*vertices+i];
                        ant[i] = v;
                    }
                }
            }
        }
    }while (v != destino -1 && min != HUGE_VAL);

/* Mostra o Resultado da busca */
printf("\tDe %d para %d: \t", origem, destino);
if (min == HUGE_VAL){
    printf("Não Existe\n");
    printf("\tCusto: \t- \n");
}
else {
    i = destino;
    i = ant[i -1];
    while(i != -1){
    tmp[cont] = i+1;
    cont++;
    i = ant[i];
}
for (i = cont; i > 0; i--){
    printf("%d -> ", tmp[i-1]);
}
    printf("%d", destino);
    printf("\n\tCusto: R$ %0f\n", (float) dist[destino-1]);
    }
}

void grafo_criar(){
    do{
        printf("\nInforme o número de vertices ( informar 5): ");
        scanf("%d", &vertices);
    }while (vertices < 3 );
    if (!custos){
        free(custos);
    }
    custos = (float *) malloc(sizeof(float)*vertices*vertices);
    //Se compilador falhou em alocar espaço na memória
    if(custos == NULL){
        //system("color fc");
        printf("** Erro: Memoria Insulficiente ** ");
        exit(-1);
    }
//Preenchendo a Matriz com -1
for (int i = 0; i<= vertices + vertices; i++){
    custos[i] = -1;
}
do{
    //system("clear");
    printf("Entre com as Arestas:\n");
    do {
        printf("Origem (entre 1 e %d, ou '0' para Sair): ", vertices);
        scanf("%d", &origem);
    } while (origem < 0 || origem > vertices);
    if (origem){
        do{
            printf("Destino (entre 1 e %d, menos %d )", vertices, origem);
            scanf("%d", &destino);
        }while (destino < 1 || destino > vertices || destino == origem);
        do{
            printf("Custo (positivo) do vertice %d para o vertice %d: ", origem, destino);
            scanf("%f", &custo);
        } while (custo < 0);
        custos[(origem-1) * vertices + destino -1] = custo;
    }
}while (origem);
}

//Busca os menores caminhos entre os vertices
void grafo_procurar(void){
    int i, j;
    system("clear");
    //system("color 03");
    printf("\nLista dos menores caminhos no Grafo Dado: \n\n");
    for (i = 1; i <= vertices; i++){
        for(j = 1; j <= vertices; j++){
            dijkstra(vertices, i, j, custos);
        }
        printf("\n");
    }
    getchar();
    //system("color 07");
}

/* Desenha o menu na tela */
void menu_mostrar(){
    printf("Implementação do Algoritmo de Dijasktra\n");
    printf("Opções:\n");
    printf("\t 1 - Adicionar um Grafo\n");
    printf("\t 2 - Procura Os Menores Caminho no Grafo\n");
    printf("\t 0 - Sair do Programa\n");
    printf("? ");
}