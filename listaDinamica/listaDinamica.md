# LISTAS DINÂMICAS
* - Objetivos de Aprendizagem
- Aprender o conceito de listas
- Usar alocação dinâmica de memória na construção de listas
- Entender como se dá a navegação em listas
* - Plano de Estudo
* - - A seguir, apresenta-se os tópicos que você estudará nesta unidade
- Fundamentos de Lista Dinâmicas
- Implementação de uma lista Dinâmica
- Lista dinâmica em forma de pilha
- Lista dinâmica em forma de fila

# Insere um elemento no final da Lista
## void lista_inserir(ptr_no lista) { //Função Inserir no final da Lista
1- enquanto (lista->proximo != NULL) { //enquanto lista->proximo for diferente de NULL
1.1-    lista = lista->proximo; //Lista vai recebendo lista proximo
    }
2-  lista->proximo = (ptr_no) malloc(sizeof(no)); //reservar memoria para lista->proximo
3-  lista = lista->proximo;
4-  lista->dado = rand()%100; //A Lista recebe um valor
5-  lista->proximo = NULL; //A Lista->proximo recebe NULL
}

# Remove um elemento da Lista
## void lista_remover(ptr_no lista) { //Funçao remover
1-  int dado; //Variavel que recebe o dado
2-  ptr_no atual; //Ponteiro no Atual
3-  atual = (ptr_no) malloc(sizeof(no)); //atual recebe Alocação dinamica de memoria
4-  Escreva("\n\nEscolha um dos itens para remoção:\n");
5-  Leia("%d", &dado); //dado para remoção
6-  Enquanto((lista->dado != dado)) {
6.1-    Se (lista->proximo == NULL) {
6.2-        pause;
        }
7-  atual = lista;
8-  lista = lista->proximo;
    }
9-  Se(lista->dado == dado) {
9.1-    atual->proximo = lista->proximo;
    }
}

# Desenha o elemento da Lista na Tela
## void lista_mostrar(ptr_no lista) {
1-  system("clear");
2-  enquanto(lista->proximo !=NULL) { //Enquanto lista proximo for diferente de NULL
2.2-      Escreva(",%d", lista->dado);
2.3-      lista = lista->proximo;
    }
4-  Escreva(",%d", lista->dado);  
}