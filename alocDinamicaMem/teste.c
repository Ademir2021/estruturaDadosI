#include <stdio.h>
#include <stdlib.h>

/*
 
 *ptr e um ponteiro esperando uma variavel ptr ser alocada dinamicamente na memória para uso.
 Exemplo: ptr = alocação dinamica na memoria, conforme linha 15
ai se usa o ponteiro *ptr

*ptr <- 300;
*ptr +<- +200;
Escreva ("O resultado será 500,00"), veja que o ponteiro *ptr carrega o valor contido na variavel ptr.

 */

int main() {
    float *ptr ,x;

    printf("Endereço: %p\n\n", ptr);
    ptr = (float *) malloc(sizeof (float));
    printf("Endereço: %p\nValor: %f\n\n", ptr, *ptr);
    x = 300;
    x += +200;
    x = x/2+3;
    ptr = &x;
    printf("Endereço: %p\nValor: R$ %.2f\n\n", ptr, *ptr);
    
    printf("Endereço: %p\nValor: %f\n\n", ptr, *ptr);
    getchar();
    return(0);
}