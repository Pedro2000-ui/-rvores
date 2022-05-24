#include "util.h"
#include <stdio.h>
#include <stdlib.h>

BST * bstNovoNo(int chave) {
    BST * no = (BST *)malloc(sizeof(BST));
    no->chave = chave;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}
int calculaAlturaBst(BST *raiz) {
  if(raiz == NULL) return 0;
  
  int esquerda = calculaAlturaBst(raiz->esq);
  int direita = calculaAlturaBst(raiz->dir);
  
  if(esquerda < direita) {
    return direita + 1;
  }
  return esquerda + 1;
}
BST * inserirBst(BST *raiz, int chaveInserir) {
    if (raiz == NULL) 
      return bstNovoNo(chaveInserir);
    if (chaveInserir > raiz->chave) 
      raiz->dir = inserirBst(raiz->dir, chaveInserir);
    else 
      raiz->esq = inserirBst(raiz->esq, chaveInserir);
  return raiz;
}
void preOrdemBST(BST *raiz) {
  if (raiz == NULL) return;
  
  if(raiz->chave < 10)
    printf("0%d ", raiz->chave);
  else
    printf("%d ", raiz->chave);  
  preOrdemBST(raiz->esq);
  preOrdemBST(raiz->dir);
}
void emOrdemBST(BST *raiz) {
  if (raiz == NULL) return;
  
  emOrdemBST(raiz->esq);
  if(raiz->chave < 10)
    printf("0%d ", raiz->chave);
  else
    printf("%d ", raiz->chave);  
  emOrdemBST(raiz->dir);
}
void posOrdemBST(BST *raiz) {
  if (raiz == NULL) return;
  
  posOrdemBST(raiz->esq);
  posOrdemBST(raiz->dir);
  if(raiz->chave < 10)
    printf("0%d ", raiz->chave);
  else
    printf("%d ", raiz->chave);  
}
void imprimirIdentBST(BST *raiz, int count) {
  if(raiz == NULL) 
  {
    return;
  } 
  imprimirIdentBST(raiz->dir, count + 1);
  for(int i = 0; i < count; i++) {
    printf("\t");
  }
  printf("%d ", raiz->chave);
  printf("\n");
  imprimirIdentBST(raiz->esq, count + 1);
}
void bstFree(BST * raiz) {
  if (raiz == NULL) return;

  if (raiz->esq != NULL)
    bstFree(raiz->esq);
  if (raiz->dir != NULL)
    bstFree(raiz->dir);
  
  free(raiz);
}
void imprimeRelatorioAtualBst(BST *raiz, int alturaAtualBst) {
  printf("\n\nÁrvore BST: \n\n");
  imprimirIdentBST(raiz, 0);
  printf("\n\tPreOrdemBST: ");
  preOrdemBST(raiz);
  printf("\n\tEmOrdemBST: ");
  emOrdemBST(raiz);
  printf("\n\tPosOrdemBST: ");
  posOrdemBST(raiz);
  printf("\n\tAltura BST: %d", alturaAtualBst);
}
void imprimeRelatorioFinalBst(double alturaGeralBst, int amostras, double tempo) {
    printf("Altura Média BST: %.2f ", alturaGeralBst / amostras);
    printf("\nTempo médio de construção BST: %fs", tempo/amostras);
} 