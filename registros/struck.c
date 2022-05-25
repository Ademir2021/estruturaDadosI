#include <stdio.h>
#include <stdlib.h>

struct fraction {
	int numerator;
	int denominator;
	float value;
};

struct fraction metade; //cria uma variavel do tipo fraction
struct fraction soma; //

int main() {

soma.numerator = 2;
soma.denominator =2;
soma.value = soma.numerator + soma.denominator;
printf("Soma: = %f \n", soma.value);

metade.numerator = 10; //atribui valor ao elemento numerador
metade.denominator = 2; //atribui valor ao elemento denominador
metade.value = metade.numerator / metade.denominator;
printf("Metade: = %f  \n", metade.value);

getchar();
return (0);
}