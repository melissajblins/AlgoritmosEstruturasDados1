#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

int menor(NoArvore *raiz) {
    while(raiz->esq){
        raiz = raiz->esq;
    }
    return raiz->chave;
}

int maior(NoArvore *raiz) {
    while(raiz->dir){
        raiz = raiz->dir;
    }
    return raiz->chave;
}