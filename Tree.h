#ifndef TREE_H
#define TREE_H
struct No{
    int valor;
    struct No* esquerda;
    struct No* direita;
};
typedef struct No No;

void inserir(No** pRaiz, int valor);
void inOrder(No* raiz);
void preOrder(No* raiz);
void postOrder(No* raiz);
No* buscar(No* raiz, int valor);
void remover(No** pRaiz, int valor);
void liberarArvore(No* raiz);

#endif
