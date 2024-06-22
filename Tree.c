#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

void inserir(No** pRaiz, int valor) {
    if (*pRaiz == NULL) {
        *pRaiz = (No*)malloc(sizeof(No));
        (*pRaiz)->valor = valor;
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
    } else {
        if (valor < (*pRaiz)->valor)
            inserir(&(*pRaiz)->esquerda, valor);
        else if (valor > (*pRaiz)->valor)
            inserir(&(*pRaiz)->direita, valor);
    }
}

void inOrder(No* raiz) {
    if (raiz != NULL) {
        inOrder(raiz->esquerda);
        printf("%d ", raiz->valor);
        inOrder(raiz->direita);
    }
}

void preOrder(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrder(raiz->esquerda);
        preOrder(raiz->direita);
    }
}

void postOrder(No* raiz) {
    if (raiz != NULL) {
        postOrder(raiz->esquerda);
        postOrder(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;
    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);
    return buscar(raiz->direita, valor);
}

void remover(No** pRaiz, int valor) {
    if (*pRaiz == NULL) {
        printf("Número não existe na árvore!\n");
        return;
    }
    if (valor < (*pRaiz)->valor)
        remover(&(*pRaiz)->esquerda, valor);
    else if (valor > (*pRaiz)->valor)
        remover(&(*pRaiz)->direita, valor);
    else {
        No* pAux = *pRaiz;
        if ((*pRaiz)->esquerda == NULL && (*pRaiz)->direita == NULL) {
            free(pAux);
            *pRaiz = NULL;
        } else if ((*pRaiz)->esquerda == NULL) {
            *pRaiz = (*pRaiz)->direita;
            pAux->direita = NULL;
            free(pAux);
        } else if ((*pRaiz)->direita == NULL) {
            *pRaiz = (*pRaiz)->esquerda;
            pAux->esquerda = NULL;
            free(pAux);
        } else {
            pAux = MaiorDireita(&(*pRaiz)->esquerda);
            pAux->direita = (*pRaiz)->direita;
            (*pRaiz)->esquerda = (*pRaiz)->direita = NULL;
            free(*pRaiz);
            *pRaiz = pAux;
        }
    }
}

void liberarArvore(No* raiz){
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}