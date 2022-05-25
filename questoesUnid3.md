# Listas Dinamicas

 1. È possivel criar uma lista de forma estática usando vetor?
- Sim, a lista pode ser implementada de forma estática num vetor ou dimanicamente na memória. O que caracteriza "lista dinâmica" é o fato de seus nós possuirem o endereço do próximo elemento, permitindo assim sua "organização" independente do indice do vetor.

2. Crie a estrutura de um "nó" para uma lista encadeada?
struct no {
   int dado;
   struct no *proximo;
 }no;

3. Crie a estrutura de um "nó" para uma lista duplamente encadeada?
 struct no {
   int dado;
   struct no *anterior;
   struct no *proximo;
 };

4. Qual a vantagem de uma lista duplamente encadeada em relação a uma lista simples?
- Na lista simples, os nós possuem apenas o endereço do próximo elemento. Dessa forma, podemos navegar do primeiro ao último nó em um unico sentido. Na lista duplamente encadeada, os nós posuem o endereço do elemento anterior e do elemento posterior. Dessa forma, podemos fazer a navegação em ambos os sentidos, tanto do início para o final como do final para o inicio.

5. Como sabemos qual é o nó inicial de uma lista simples
- Só é possível saber onde começa uma lista dinâmica se tivermos uma variável do tipo ponteiro que aponte para o início da lista.

6. Como sabemos qual é o nó final de uma lista simples
- Sabemos se um nó é o último de uma lista se o atributo que aponta para o próximo elemento estiver com o  valor nulo(NULL)

7. Se um nó de uma lista duplamene encadeada possui dois ponteiros, um para o
próximo elemento e um para o anterior, qual informação está contida nesses ponteiros do primeiro nó da lista
- o primeiro nó de uma lista duplamente encadeada tem dois ponteiro, assim como todos os demais nós.
O ponteiro criado para apontar para o elemento anterior estará apntando para nullo, já que como é o primeiro nó, não há um nó anterior. O outro ponteiro estará apontando para o proximo nó. Se por acaso só haja um nó nessa lista duplamente encadeada, ambos os ponteiros estarão apontando para nullo.
