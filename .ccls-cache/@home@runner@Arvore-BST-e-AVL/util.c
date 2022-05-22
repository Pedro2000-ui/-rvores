#include <stdlib.h>
#include <stdio.h>
#include "util.h"

int *geraNumAleatorios(int num) {
  
  int *numAleatorios = (int *)malloc(sizeof(int) *num);
  for (int i = 0; i < num; i++) {
    numAleatorios[i] = rand() % (100 * num) + 1;
  }
  return numAleatorios;
}
void imprimeRelatorioFinalGeral(double alturaMediaAvl, double alturaMediaBst, double tempoGeral, int amostras) {
  
  double alturaMediaGeral;
  alturaMediaGeral = ((alturaMediaAvl + alturaMediaBst) / amostras) / 2;
  printf("\nAltura Média Geral: %.2f", alturaMediaGeral);
  printf("\nTempo médio de construção Geral: %fs", tempoGeral/amostras);
}
