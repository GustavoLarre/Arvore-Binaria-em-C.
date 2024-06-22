#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

int main(){
     No* raiz = NULL;

    inserir(&raiz, 50);
    inserir(&raiz, 30);
    inserir(&raiz, 90);
    inserir(&raiz, 20); 
    inserir(&raiz, 40);
    inserir(&raiz, 95);

    printf("In-Order:\n");
    inOrder(raiz);

    printf("Pre-Order:\n");
    preOrder(raiz);

    printf("Post-Order:\n");
    postOrder(raiz);

    remover(&raiz, 30);
    printf("Árvore após a remoção:\n");
    imprimir(raiz);

    liberarArvore(raiz);

    return 0;
}