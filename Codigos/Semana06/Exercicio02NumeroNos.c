#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

int numero_nos(NoArvore *raiz){
    if(raiz == NULL)
        return 0;
    else
        return 1 + numero_nos(raiz->esq) + numero_nos(raiz->dir);
}

int numero_nos_folha(NoArvore *raiz){
    if(raiz == NULL)
        return 0;
    else if(raiz->esq == NULL && raiz->dir == NULL)
        return 1;
    else
        return numero_nos_folha(raiz->esq) + numero_nos_folha(raiz->dir);
}

int numero_nos_internos(NoArvore *raiz){
    return (numero_nos(raiz) - numero_nos_folha(raiz));
}