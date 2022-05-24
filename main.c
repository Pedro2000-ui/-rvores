#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "util.h"


int main(void) {
  int escolha, amostras, nos;
  srand(time(NULL));
  do{
    double somaAlturaGeralAvl = 0;
    double somaAlturaGeralBst = 0;
    double tempo1 = 0; 
    double tempo2 = 0;
    double tempoGeral = 0;
    system("clear");
    printf("\n-----------------MENU-----------------");
    printf("\nNúmero de Amostras: ");
    scanf("%d", &amostras);
    printf("Número de Nós: ");
    scanf("%d", &nos);
    printf("\n");
    
    for(int i = 0; i < amostras; i++) {
      BST *auxBst = (BST *)malloc(sizeof(BST));
      AVL *auxAvl = (AVL *)malloc(sizeof(AVL));
      int *numeros;
      clock_t ini, fim;
      
      auxAvl = NULL;
      auxBst = NULL;
      numeros = geraNumAleatorios(nos);
      printf("\n---------- Relatório Atual ----------\n\n");
      printf("Amostra: %d\n", i + 1);
      printf("OrdemInserção: ");
      
      ini = clock();
      for(int j = 0; j < nos; j++) {
        auxAvl = inserirAvl(auxAvl, numeros[j]);
        printf("%d ", numeros[j]);
      }
      fim = clock();
      tempo1 += (double) (fim - ini) / CLOCKS_PER_SEC;
      ini = clock();
      for(int j = 0; j < nos; j++) {
        auxBst = inserirBst(auxBst, numeros[j]);
      }
      fim = clock();
      tempo2 += (double) (fim - ini) / CLOCKS_PER_SEC;
      tempoGeral += tempo1 + tempo2;
      int alturaAtualAvl = getAlturaAvl(auxAvl);
      int alturaAtualBst = calculaAlturaBst(auxBst);
      
      somaAlturaGeralAvl += alturaAtualAvl;
      somaAlturaGeralBst += alturaAtualBst;

      imprimeRelatorioAtualAvl(auxAvl, alturaAtualAvl);
      imprimeRelatorioAtualBst(auxBst, alturaAtualBst);

      free(numeros);
      bstFree(auxBst);
      avlFree(auxAvl);
      printf("\n");
    }
    
    printf("\n---------- Relatório Final ----------\n\n");
    imprimeRelatorioFinalAvl(somaAlturaGeralAvl, amostras, tempo1);
    printf("\n\n-------------------------------------\n\n");
    imprimeRelatorioFinalBst(somaAlturaGeralBst, amostras, tempo2);
    printf("\n\n-------------------------------------\n\n");
    imprimeRelatorioFinalGeral(somaAlturaGeralAvl, somaAlturaGeralBst, tempoGeral, amostras);
    
    printf("\n1 - Nova Simulação ou 0 - Sair\n_");
    scanf("%d", &escolha);
    
  } while(escolha);
  
  
  printf("Fim...");
  return 0;
}