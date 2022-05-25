# Dijkastra - Algoritmo

1. Dijkstra()Grafo G, Vértice inicial, Vértice final);
2. corrente <- inicio
3. Para cada vertie v adjacente a corrente \\Use o for
4.      Calcule o custo de inicio até v
5.      O Custo é o menor até o momento?
6.          corrente <- v
7. corrente <- vértice com o menor custo desde inicio
8. se corrente = final
9.     encerre o algortimo
10. Se não, volte até o passo 3