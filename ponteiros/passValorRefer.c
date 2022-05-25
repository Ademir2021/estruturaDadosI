#include <stdio.h>

int calcQuadradoV(int x);
int calcQuadradoR(int *x);

int main() {
    int num, resposta;
    printf("\nDigite um número Inteiro: \n\n");
    scanf("%d", &num);

    resposta = calcQuadradoV(num); //se for por referencia inclua o & no "argumento" num;
    printf("O quadrado do número %d passado por valor é %d\n", num, resposta);

    resposta = calcQuadradoR(&num); //se for por referencia inclua o & no "argumento" num;
    printf("O quadrado do número %d passado por referencia é %d\n", num, resposta);
}

int calcQuadradoV(int x) { //Retorna paramentro por valor
    x = x * x;
    return x;
}

int calcQuadradoR(int *x) { //Retorna parametro por referencia
    *x = *x * (*x);
    return *x;
}