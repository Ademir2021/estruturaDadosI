#include <stdio.h>
#include <stdlib.h>

int xi;
int *ptr_xi;

float xf;
float *ptr_xf;

char xc;
char *ptr_xc;

/**
Agora vamos fazer uma função imprimir(). que vai desenhar na tela o valor de xi, &xi, ptr_xi e *ptr_xi
Lembrando que xi é uma variável do tipo inteiro e &xi é um ponteiro que aponta para o endereço onde xi
está está armazenado na memória. A varíavel ptr_xi é um ponteiro para um inteiro e *ptr_xi é o valor
para o qual o ponteiro ptrxi está apontando.
Dentro da função main(), vamos atrbuir o valor 10 para xi e o valor de &x para ptr_xi. Em seguida,
vamos chamar a funçãoimprimir() e observe o resultado.
*/

void imprimir(){
    printf("Valor de xi = %d \n", xi);
    printf("Valor de &xi = %p \n", &xi);
    printf("Valor de ptr_xi = %p \n", ptr_xi);
    printf("Valor de *ptr_xi = %d \n", *ptr_xi);
}

int main() {
    xi = 10;
    ptr_xi =&xi;
    imprimir();

    xi = 20;
    imprimir();

    *ptr_xi = 30;
    imprimir();

    getchar();
    return(0);
}