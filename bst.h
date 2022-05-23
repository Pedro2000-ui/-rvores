typedef struct BST {
  int chave;
  struct BST* esq;
  struct BST* dir;
} BST;

BST * bstNovoNo(int chave);
/* Insere um novo Nó e o retorna */
int calculaAlturaBst(BST *raiz);
/* Calcula a Altura Atual de um determinado nó e retorna essa altura */
BST * inserirBst(BST *raiz, int chaveInserir);
/* Insere um novo no e retorna a arvore atual*/
void preOrdemBST(BST *raiz);
/* Imprime a Árvore atual em PreOrdem */
void emOrdemBST(BST *raiz);
/* Imprime a Árvore atual em EmOrdem */
void posOrdemBST(BST *raiz);
/* Imprime a Árvore atual em PosOrdem */
void imprimirIdentBST(BST *raiz, int count);
/* Imprime a Árvore Atual de forma Indentada, parecida com um desenho real de uma Árvore */
void bstFree(BST * raiz);
/* Libera a Memória da Árvore atual de forma recursiva */
void imprimeRelatorioAtualBst(BST *raiz, int somaAlturaAtualBst);
/* Imprime o Relatório Atual da Árvore (reseta e imprime um novo relatório conforme troca a Amostra, 
já que roda em um loop) */
void imprimeRelatorioFinalBst(double alturaGeralBst, int amostras, double tempo);
/* Imprime o Relatório Final da Árvore */