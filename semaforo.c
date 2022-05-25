#include <stdio.h>
#include <stdlib.h>

struct semaforo {
    char cor[10];
    int id;
};

struct semaforo s1 = {"Vermelho", 1};
struct semaforo s2 = {"Amarelo", 2};
struct semaforo s3 = {"Verde", 3};
struct semaforo *ptr_s;

int main() {
    ptr_s = &s1;
    printf("%d - %s\n", (*ptr_s).id, (*ptr_s).cor);
    ptr_s = ptr_s + 1;
    printf("%d - %s\n", (*ptr_s).id, (*ptr_s).cor);
    ptr_s = ptr_s + 1;
    printf("%d - %s\n", (*ptr_s).id, (*ptr_s).cor);
    getchar();
    return 0;
}