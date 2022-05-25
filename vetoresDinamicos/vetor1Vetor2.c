#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tamanho;
int *vetor1, *vetor2;

int main() {
    int i;
    printf("Escolha o tamanho do vetor: ");
    scanf("%d", &tamanho);
    vetor1 = (int *) malloc(sizeof (int)* tamanho);
    vetor2 = (int *) malloc(sizeof (int)* (tamanho * 2));

    printf("\nVetor1[i]: \n");
    for (i = 0; i < tamanho; i++) {
        vetor1[i] = pow(2,i);
        printf("Posição %d: %d\n", i, vetor1[i]);
    }
    printf("\nVetor2: \n");
    for (i = 0; i < tamanho*2; i++) {
        vetor2[i] = pow(3,i);
        printf("Posição %d: %d\n", i, vetor2[i]);
    }
    getchar();
    return 0;
}