#include <stdio.h>
#include <stdlib.h>
int main () {
    int *ptr;
     ptr = (int *) malloc(sizeof (int));
     int x = 45;
     ptr = &x;
      printf("Endereco: %p, %d\n\n",ptr, *ptr);

    getchar();
    return(0);
}