#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
    setlocale(LC_ALL, "portuguese");
    int x, y;

    printf("Digite o valor de X: ");
    scanf("%d",&x);
    system("clear");
    printf("Digite o valor de Y: ");
    scanf("%d", &y);
    system("clear");

    if (x+y >= 10){
        printf("OK\n");
    }else{
        x = x+y;
    printf("%d\n", x);
    }
    
    printf("Fim\n");

    getchar();
    return 0;
}