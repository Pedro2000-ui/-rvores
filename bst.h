typedef struct BST {
  int chave;
  struct BST* esq;
  struct BST* dir;
} BST;

BST * bstNovoNo(int chave);
int calculaAlturaBst(BST *raiz);
BST * inserirBst(BST *raiz, int chaveInserir);
void preOrdemBST(BST *raiz);
void emOrdemBST(BST *raiz);
void posOrdemBST(BST *raiz);
void imprimirIdentBST(BST *raiz, int count);
void bstFree(BST * raiz);
void imprimeRelatorioAtualBst(BST *raiz, int somaAlturaAtualBst);
void imprimeRelatorioFinalBst(double alturaGeralBst, int amostras, double tempo);