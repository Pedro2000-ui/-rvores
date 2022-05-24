#include "util.h"
#include <stdio.h>
#include <stdlib.h>

AVL * avlNovoNo(int chave) {
    AVL * no = (AVL *)malloc(sizeof(AVL));
    no->chave = chave;
    no->altura = 1;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}
int getAlturaAvl(AVL *raiz) {
  if (raiz == NULL) return 0;
  return raiz->altura;
}
int calculaFbAvl(AVL *no) {
  return getAlturaAvl(no->esq) - getAlturaAvl(no->dir);
}
int calculaAlturaAvl(AVL *raiz) {
  if(raiz == NULL) return 0;
  int esquerda = calculaAlturaAvl(raiz->esq);
  int direita = calculaAlturaAvl(raiz->dir);

  if(esquerda < direita) {
    return direita + 1;
  }
  return esquerda + 1;
}
AVL * RotL(AVL * raiz) {
  if (raiz == NULL) return raiz;
  
  AVL * novaRaiz = raiz->dir;
  raiz->dir = novaRaiz->esq;
  novaRaiz->esq = raiz;
  raiz->altura = calculaAlturaAvl(raiz);
  novaRaiz->altura = calculaAlturaAvl(novaRaiz);
  
  return novaRaiz;
}
AVL * RotR(AVL * raiz) {
  if (raiz == NULL) return raiz;
  
  AVL * novaRaiz = raiz->esq;
  raiz->esq = novaRaiz->dir;
  novaRaiz->dir = raiz;
  raiz->altura = calculaAlturaAvl(raiz);
  novaRaiz->altura = calculaAlturaAvl(novaRaiz);
  
  return novaRaiz;
}
AVL * inserirAvl(AVL *raiz, int chave) {
  if (raiz == NULL)
    return avlNovoNo(chave);
  
  if (chave > raiz->chave)
    raiz->dir = inserirAvl(raiz->dir, chave);
  else
    raiz->esq = inserirAvl(raiz->esq, chave);

  raiz->altura = calculaAlturaAvl(raiz);
  int fb = calculaFbAvl(raiz);
  
  if (fb == 2) { 
    if (calculaFbAvl(raiz->esq) < 0) {
      raiz->esq = RotL(raiz->esq);
    }
    raiz = RotR(raiz); 
  }
  else if (fb == -2) {
    if (calculaFbAvl(raiz->dir) > 0) {
      raiz->dir = RotR(raiz->dir);
    }
    raiz = RotL(raiz);
  }
  return raiz;
}
void preOrdemAVL(AVL *raiz) {
  if (raiz == NULL) return;
  
  if(raiz->chave < 10)
    printf("0%d ", raiz->chave);
  else
    printf("%d ", raiz->chave);  
  preOrdemAVL(raiz->esq);
  preOrdemAVL(raiz->dir);
}
void emOrdemAVL(AVL *raiz) {
  if (raiz == NULL) return;
  
  emOrdemAVL(raiz->esq);
  if(raiz->chave < 10)
    printf("0%d ", raiz->chave);
  else
    printf("%d ", raiz->chave);  
  emOrdemAVL(raiz->dir);
}
void posOrdemAVL(AVL *raiz) {
  if (raiz == NULL) return;
  
  posOrdemAVL(raiz->esq);
  posOrdemAVL(raiz->dir);
  if(raiz->chave < 10)
    printf("0%d ", raiz->chave);
  else
    printf("%d ", raiz->chave);  
}
void avlFree(AVL * raiz) {
  if (raiz == NULL) return;

  if (raiz->esq != NULL)
    avlFree(raiz->esq);
  if (raiz->dir != NULL)
    avlFree(raiz->dir);
  
  free(raiz);
}
void imprimirIdentAVL(AVL *raiz, int count) {
  if(raiz == NULL) 
  {
    return;
  } 
  imprimirIdentAVL(raiz->dir, count + 1);
  for(int i = 0; i < count; i++) {
    printf("\t");
  }
  printf("%d ", raiz->chave);
  printf("\n");
  imprimirIdentAVL(raiz->esq, count + 1);
}
void imprimeRelatorioAtualAvl(AVL *raiz, int alturaAtualAvl) {
  printf("\n\nÁrvore AVL: \n\n");
  imprimirIdentAVL(raiz, 0);
  printf("\n\tPreOrdemAVL: ");
  preOrdemAVL(raiz);
  printf("\n\tEmOrdemAVL: ");
  emOrdemAVL(raiz);
  printf("\n\tPosOrdemAVL: ");
  posOrdemAVL(raiz);
  printf("\n\tAltura AVL: %d", alturaAtualAvl);
}
void imprimeRelatorioFinalAvl(double alturaGeralAvl, int amostras, double tempo) {
    printf("Altura Média AVL: %.2f ", alturaGeralAvl / amostras);
    printf("\nTempo médio de construção AVL: %fs", tempo/amostras);
}
