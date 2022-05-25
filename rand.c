#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int result=0;
    srand(time(NULL));

    result = rand()%100;

    printf("%d\n", result);

    return(0);
    getchar();
}