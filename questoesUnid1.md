# Ponteiros

3. Qual a diferença entre uma varíavel do tipo inteira de um ponteiro do tipo inteiro?
- Uma variável do tipo inteira aponta pra um número inteiro na memória, já um ponteiro do tipo inteiro aponta para o endereço de um inteiro na memória, seja o de uma variável estática ou dinâmica.

4. Por que devemos preencher um ponteiro apenas com o endereço de uma váriavel ou por alocação dinamica usando funções como o malloc?
- Porque se tentarmos alocar indiscriminadamente um endereço qualquer a um ponteiro, corremos o risco de estar manipulando uma área da memória que está sendo utilizada por outro programa ou até mesmo pelo sistema operacional, o que pode causar instabilidade no computador.

# Ponteiros Resumo
- Uma variável é um "Objeto" que representa um espaço reservado na memória.
Quando escolhemos o tipo de variável, estamos definindo o tamanho de bytes que ele terá e as regras de como seus bits serão lidos, conforme foi discutido no inicio do livro.
Um ponteiro tem 4 bytes(32 bits), assim como um número real, só que no número inteiro positivo todo os bits são siginificativos, enquanto na variável de ponto flutuante só os primeiro 24 representam valor, os últimos 8 determinam a posição da casa decimal no número.
Por isso quando encontramos uma variável de 4 bytes alocada na memória, precisamos saber qual o seu tipo para fazer a sua correta leitura. Ao invés de obter o valor armazenado numa variável, podemos opcionalmente obter o seu endereço na memoria. Por exemplo, criamos uma variável x do tipo inteiro; para saber qual o seu endereço, usamos a notação &x. Isso siginifica que &x é um "ponteiro" que aponta para seu endereço da variavel x na memória.
Também é possível usar um ponteiro como tipo de dados na declaração de uma variavel, só que nesse caso ele não irá quardar um valor, "mas sim uma posição na memória." Vejamos agora exemplos de criação de variáveis e ponteiros.
- int xi;
- int *ptr_xi;

- float xf
- floar *ptr_xf;

- char xc;
- char *ptr_xc;
A variável xi do tipo inteiro e ptr_xi é um ponteiro que aponta para uma variável do tipo inteiro. A mesma relação existe para xf e ptr_xf, só que no caso deles é para armazenar um valor de ponto flutuante e um ponteiro para um ponto flutuante. Por último, xc é uma variável do tipo caractere e ptr_xc, um ponteiro para um caractere.
Segundo Tenenbaum(1995,p,29),"[...]um ponteiro é como qualquer outro tipo de dado em C. O valor de um ponteiro é uma posição na memória da mesma forma que um valor de um inteiro é um número. Os valores dos ponteiros podem ser atribuidos como quaisquer outros valores."
A imagem a seguir simula um espaço na memória. Na parte de cima estão os endereços e, na parte de baixo, os valores contidos naquels posições. Essa ilustração ajuda a enender melhor o conceito de ponteiro e a sua relação com uma variável.
Como ptr_xi é um ponteiro, não posso simplesmente atribuir a ele o valor de xi, preciso, sim, atribuir o endereço que xi ocupa na memória. Para isso, usamos a anotação &xi, que significa "O ponteiro que aponta para o endereço na memória da variável xi".
- int xi;
- int *ptr_xi;
Agora vamos fazer uma função chamada imprimir(), que vai desenhar na tela o valor de xi, &xi, ptr_xi e *ptr_xi.
void imprimir() {
    printf("Valor de xi = %d \n", xi);
    printf("Valor de &xi = %p \n", &xi);
    printf("Valor de ptr_xi = %p \n", ptr_xi);
    printf("Valor de *ptr_xi = %d \n", *ptr_xi);
}
Lembrando que xi é uma váriavel do tipo inteiro e &xi é o ponteiro que aponta para o endereço onde xi está armazenada na memória. A variável ptr_xi é um ponteiro para um inteiro e *ptr_xi é o valor para o qual o ponteiro ptr_xi está apontando.
Dentro da função main(), vamos atribuir o valor 10 para para xi e o valor de &xi para ptr_xi. Em seguida vamos chamar a função imprimir() e observar o resultado.
int main() {
    xi = 10;
    ptr_xi = &x;
    imprimir();
}

