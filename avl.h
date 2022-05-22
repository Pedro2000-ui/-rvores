
typedef struct AVL {
  int chave;
  int altura;
  struct AVL* esq;
  struct AVL* dir;
} AVL;

AVL * avlNovoNo(int chave);
int getAlturaAvl(AVL *raiz);
int calculaFbAvl(AVL *no);
int calculaAlturaAvl(AVL *raiz);
AVL * RotL(AVL * raiz);
AVL * RotR(AVL * raiz);
AVL * inserirAvl(AVL *raiz, int chave);
void preOrdemAVL(AVL *raiz);
void emOrdemAVL(AVL *raiz);
void posOrdemAVL(AVL *raiz);
void avlFree(AVL * raiz);
void imprimirIdentAVL(AVL *raiz, int count);
void imprimeRelatorioAtualAvl(AVL *raiz, int somaAlturaAtualAvl);
void imprimeRelatorioFinalAvl(double alturaGeralAvl, int amostras, double tempo);

