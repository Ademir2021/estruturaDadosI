#include <stdio.h>
#include <stdlib.h>
//#define tam 10
int main() {
    int *p;
   //p = (int *) malloc(sizeof(4)); //Alocação estatica de memória
    p = (int *) malloc(sizeof(int)); //Alocação dinamica de memória
    //p = (int *) malloc(sizeof(int)*tam); //Alocação vetor dinamica de memória
    if(p == NULL) {
        printf("Erro\n");
    }
    else
    {
        *p = 10;
        printf("p: %d | %p\n", *p ,p);
        free(p);
    }
}