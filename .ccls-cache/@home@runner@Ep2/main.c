#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct BST {
  int chave;
  struct BST* esq;
  struct BST* dir;
} BST;

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



typedef struct AVL {
  int chave;
  int altura;
  struct AVL* esq;
  struct AVL* dir;
} AVL;



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

int *geraNumAleatorios(int num) {
  
  int *numAleatorios = (int *)malloc(sizeof(int) *num);
  for (int i = 0; i < num; i++) {
    numAleatorios[i] = rand() % (100 * num) + 1;
  }
  return numAleatorios;
}

int main(void) {
  int escolha, amostras, nos;
  srand(time(NULL));
  do{
    double alturaMediaAvl = 0;
    double alturaMediaBst = 0;
    double alturaMediaArvores;
    system("clear");
    printf("\n-----------------MENU-----------------");
    printf("\nNúmero de Amostras: ");
    scanf("%d", &amostras);
    printf("Número de Nós: ");
    scanf("%d", &nos);
    printf("\n");
    
    for(int i = 0; i < amostras; i++) {
      int somaAlturaAvl = 0; int somaAlturaBst = 0;
      BST *auxBst = (BST *)malloc(sizeof(BST));
      AVL *auxAvl = (AVL *)malloc(sizeof(AVL));
      int *numeros;
      
      auxAvl = NULL;
      auxBst = NULL;
      numeros = geraNumAleatorios(nos);
      
      printf("Amostra: %d\n", i + 1);
      printf("\tOrdemInserção: ");
      
      for(int j = 0; j < nos; j++) {
        auxAvl = inserirAvl(auxAvl, numeros[j]);
        auxBst = inserirBst(auxBst, numeros[j]);
        printf("%d ", numeros[j]);
      }
      somaAlturaAvl += somaAlturaAvl + getAlturaAvl(auxAvl);
      alturaMediaAvl += somaAlturaAvl;
      somaAlturaBst += somaAlturaBst + calculaAlturaBst(auxBst);
      alturaMediaBst += somaAlturaBst;
      
      printf("\n\tPreOrdemBST: ");
      preOrdemBST(auxBst);
      printf("\n\tPreOrdemAVL: ");
      preOrdemAVL(auxAvl);
      printf("\n\tEmOrdemBST: ");
      emOrdemBST(auxBst);
      printf("\n\tEmOrdemAVL: ");
      emOrdemAVL(auxAvl);
      printf("\n\tPosOrdemBST: ");
      posOrdemBST(auxBst);
      printf("\n\tPosOrdemAVL: ");
      posOrdemAVL(auxAvl);
      printf("\n");
      printf("\n\tAltura AVL: %d", somaAlturaAvl);
      printf("\n\tAltura BST: %d\n", somaAlturaBst);

      printf("\nÁrvore AVL: \n\n");
      imprimirIdentAVL(auxAvl, 0);

      printf("\nÁrvore BST: \n\n");
      imprimirIdentBST(auxBst, 0);
      free(numeros);
      bstFree(auxBst);
      avlFree(auxAvl);
      printf("\n");
    }
    
    alturaMediaAvl = alturaMediaAvl / amostras;
    alturaMediaBst = alturaMediaBst / amostras;
    alturaMediaArvores = (alturaMediaAvl + alturaMediaBst) / 2;
    
    printf("Altura Média AVL: %.2f ", alturaMediaAvl);
    printf("\nAltura Média BST: %.2f", alturaMediaBst);
    printf("\nAltura Média Geral: %.2f", alturaMediaArvores);
    printf("\n1 - Nova Simulação ou 2 - Sair\n_");
    scanf("%d", &escolha);
    
  } while(escolha);
  
  
  printf("Fim...");
  return 0;
}