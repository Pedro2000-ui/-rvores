# Árvores
Exercício Programa Estrutura de Dados
- Consiste em um programa que avalia o tempo de execução de construção de uma Árvore AVL com um Árvore BST.

## Estrutura Árvore BST

|BST|
|---|
|int chave|
|BST esq|
|BST dir|

## Estrutura Árvore AVL

|AVL|
|---|
|int chave|
|int altura|
|BST esq|
|BST dir|

## Principais Funções

Existe uma função de impressão dos relatórios atuais e relatório geral, separados pelas estruturas de Árvores, ou seja, cada estrutura de Árvore é responsável pela impressão e tratamento dos seus próprios Relatórios.
O relatório Atual vai sendo atualizado e mostrado a cada mudança de amostra, já o relatório geral é apenas mostrado uma vez ao final do programa.

### RelatórioAtualBST
- Mostra na tela o desenho da árvore BST, as impressões em PreOrdem, EmOrdem e PosOrdem, e a Altura da árvore. (baseada na amostra atual)

### RelatórioFinalBST
- Imprime o relatório final com a média das alturas e o tempo médio de construção de todas as árvores BST's criadas ao longo do programa

### RelatórioAtualAVL
- Mostra na tela o desenho da árvore AVL, as impressões em PreOrdem, EmOrdem e PosOrdem, e a Altura da árvore. (baseada na amostra atual)

### RelatórioFinalAVL
- Imprime o relatório final com a média das alturas e o tempo médio de construção de todas as árvores AVL's criadas ao longo do programa

### RelatórioFinalGeral
- Imprime o relatório final, baseado nos Relatórios Finais executados em cada estrutura de Árvore. Nesse relatório é mostrado a média das alturas e o tempo médio de construção de todas as árvores criadas ao longo do programa (BST e AVL)


Existe uma função que gera números aleatórios e os retorna a cada nova execução de amostra. O intervalo de números randômicos gerados é baseado no números de nós pedido pelo usuário, através da fórmula: 
- rand() % (100 * num) + 1 onde N é o números de Nós.

Assim, caso o usuário peça amostras com árvores de 6 nós, o intervalo de números sorteados será de 1 a 600, diminuindo as chances de ser sorteado um número repetido. Para esse caso em específico as chances seriam de 0,16% de se repetir um número, pois 1/600 * 100 = 0,16%, ou seja, quanto maior o número de nós, menor a chance de ocorrer um caso de repetição.

