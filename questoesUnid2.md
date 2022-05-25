# Pilhas e Filas

1. Quando um livro e devolvido na Biblioteca do Unicesumar, o funcionário responsável pelo recebimento coloca o livro em cima de uma pilha de livros na mesa ao lado da recepção. O auxiliar de biblioteca pega o livro do topo da pilha, verifica seu código e leva-o para seu devido lugar no acervo.
No atual sistema de informação, é possivel verificar se o livro está disponível ou se está emprestado. Entretanto o livro acabou que acabou de ser devolvido ainda não se enconra na parteleira, pois existe um intervalo de tempo entre a devolução do mesmo e o momento em que ele é guardado na estante.
"A sugestão do departamento de TI é de criar um programa" que faça o controle na pilha, assim, pode-se verificar se o livro ainda não foi guardado e qual a sua posição dentro da pilha de livros que aguardam ao lado da recepção.

- A) Crie uma estrutura para a pilha de livros. Lembre-se de que ela tem que ter um vetor para armazenar os dados (código, nome do livro e autor) e dois números inteiros, um para controlar o inicio e outro para o final da pilha.

#include <string.h>

#define tamanho 50

struct tlivro {
    int codigo;
    char nome[50];
    char autor[50];
};

struct tpilha {
    tlivro dados[tamanho];
    int ini;
    int fim;
};

- B) Defina uma variável que será um vetor do tipo pilha de livros.

tpilha pilha;

- C) Faça uma função de empilhamento, lembrando-se de verificar se a pilha atingiu o tamanho máximo de livros (a mesa não aquenta muito peso).

void pilha_entrar() {
    if (pilha.fim == tamanho) {
        printf("\nA pilha está cheia, impossivel empilhar!\n\n");
        system("clear");
    }
    else {
        printf("\nDigite o código do livro: ");
        scanf("%d", &pilha.dados[pilha.fim].codigo);
        printf("\nDigite o nome do livro: ");
        scanf("%d", &pilha.dados[pilha.fim].nome);
        printf("\nDigite o nome do autor: ");
        scanf("%d", &pilha.dados[pilha.fim].autor);
        pilha.fim++;
    }
}

- D) Crie uma função para desempilhar os livros. Não se esqueça de que é necessario verificar se ainda existem livros para ser quardados.

void pilha_sair() {
    if (pilha.ini == pilha.fim) {
        printf("\nA pilha está vazia, impossivel desempilhar!\n\n");
        getchar();
    }
    else {
        pilha.dados[pilha.fim -1].codigo = 0;
        strcpy(pilha.dados[pilha.fim -1].nome, "");
        strcpy(pilha.dados[pilha.fim -1].autor, "");
        pilha.fim--;
    }
}

- E) Elabore uma função que apresente na tela a lista de todos os livros que se encontram empilhados ao lado da recepção.

void pilha_mostrar() {
    int i;
    printf("[ ");
    for (i=0; i < tamanho; i++) {
        printf("%d", pilha.dados[i].codigo);
    }
    printf("]\n\n");
}

2. Uma agência bancária quer inovar seu atendimento, criando mais conforto para seus clientes. Para isso, foram colocadas diversas cadeiras na recepção do banco. quando um cliente chega, o atendente lança no computador o seu nome e horário que chegou. Assim que um caixa fica livre, a recepcionista olha no sistema e chama pelo primeiro nome do Cliente da fila. Dessa forma, é possível que os clientes esperem confortavemente sentados pelo seu atendiemento, não imporando o local onde se encontra dentro da agencia bancária.

- A) Faça uma estrutura para o controle de fila. Você precisa guardar o nome e a hora que o cliente chegou. Use um vetor para armazenar os dados e dois numeros inteiros, para controlar o início e outro o final da fila.

#include <string.h>

#define tamanho 5

struct tcliente {
    char nome[50];
    char hora[6];
};

struct tfila {
    struct tcliente dados[tamanho];
    int ini;
    int fim;
};

- B) Defina uma variavel que será um vetor do tipo fila de clientes.

struct tfila fila

- C) Crie uma função enfileirar, lembrando que é preciso verificar se há espaço na fila(o número de cadeiras na recepção é limitado).

void fila_entrar() {
    if (fila.fim == tamanho) {
        printf("\nAfila está cheia, volte outro dia!\n\n");
        getchar();
    }
    else {
        printf("\nDigite o cliente que chegou: ");
        scanf("%s, fila.dados[fila.fim].nome);
        printf("\nDigite a hora da chegada do cliente: ");
        scanf("%s", fila.dados[fila.fim].hora);
        fila.fim++;
    }
}

- D) Elabore uma função desenfileirar cliente, não se esqueça de que é necessário verificar se ainda existem clientes para serem atendidos.

void fila_sair() {
    if (fila.ini == fila.fim) {
        printf("\nFila Vazia, mas logo chega alguém!\n\n");
        getchar();
    }
    else {
        int i;
        for (i = 0; i < tamanho; i ++) {
            strcpy(fila.dados[i], fila.fim[i+1].nome);
            strcpy(fila.dados[i], fila.fim[i+1].nome);
        }
        strcpy(fila.dados[fila.fim].nome, "");
        strcpy(fila.dados[fila.fim].hora, "");
        fila.fim--;
    }
}

- E) Faça uma função que apresente na tela a lista de todos os clientes que estão aguardando atendimento na recepção.

void fila_mostrar() {
    int i;
    printf("[ ");
    for (i=0; i < tamanho; i++) {
        printf("cliente %s", fila.dados[i].nome);
        printf(chegou as %s horas \n, fila.dados[i].hora);
    }
    printf("]"\n\n);
}

