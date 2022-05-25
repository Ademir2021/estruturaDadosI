#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int *ptr;

void alocacaoDinamica(void);

int main(){
setlocale(LC_ALL, "Portuguese");

alocacaoDinamica();
    
    system("pause");
    return 0;
}

void alocacaoDinamica(void){
 ptr = (int *) malloc(sizeof(int));
    printf("\nDigite o número inteiro 54: ");
    scanf("%d", &*ptr);
    printf("\nEndereço do ponteiro: %p\tValor contido: %d\n\n", ptr, *ptr);
}