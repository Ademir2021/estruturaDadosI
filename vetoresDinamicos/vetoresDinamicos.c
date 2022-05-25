#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    int tam;
    int *vetor;
    printf("Escolha o tamanho do vetor: ");
    scanf("%d", &tam);
    vetor = (int *) malloc(sizeof (int)*tam);
    for (int i = 0; i< tam; i++) {
        vetor[i] = pow(8, i);
        printf("Posicao:%d: Valor:%d Endereço de memoria continua o mesmo:%p\n", i, vetor[i], vetor);
    }
    getchar();
    return(0);
}
