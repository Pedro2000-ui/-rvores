
typedef struct AVL {
  int chave;
  int altura;
  struct AVL* esq;
  struct AVL* dir;
} AVL;


AVL * avlNovoNo(int chave);
/* Insere um novo Nó e o retorna */
int getAlturaAvl(AVL *raiz);
/* Pega a Altura atual de um determinado Nó e retorna essa altura */
int calculaFbAvl(AVL *no);
/* Calcula o fator de balanceamento atual 
para verificar se há necessidade 
de rotacionar e retorna esse fator*/
int calculaAlturaAvl(AVL *raiz);
/* Calcula a Altura Atual de um determinado nó e retorna essa altura */
AVL * RotL(AVL * raiz);
/* Rotaciona para esquerda com base em um determinado nó e retorna esse novo no  */
AVL * RotR(AVL * raiz);
/* Rotaciona para direita com base em um determinado nó e retorna esse novo no  */
AVL * inserirAvl(AVL *raiz, int chave);
/* Insere um novo no e retorna a arvore atual*/
void preOrdemAVL(AVL *raiz);
/* Imprime a Árvore atual em PreOrdem */
void emOrdemAVL(AVL *raiz);
/* Imprime a Árvore atual em EmOrdem */
void posOrdemAVL(AVL *raiz);
/* Imprime a Árvore atual em PosOrdem */
void avlFree(AVL * raiz);
/* Libera a Memória da Árvore atual de forma recursiva */
void imprimirIdentAVL(AVL *raiz, int count);
/* Imprime a Árvore Atual de forma Indentada, parecida com um desenho real de uma Árvore */
void imprimeRelatorioAtualAvl(AVL *raiz, int somaAlturaAtualAvl);
/* Imprime o Relatório Atual da Árvore (reseta e imprime um novo relatório conforme troca a Amostra, 
já que roda em um loop) */
void imprimeRelatorioFinalAvl(double alturaGeralAvl, int amostras, double tempo);
/* Imprime o Relatório Final da Árvore */

