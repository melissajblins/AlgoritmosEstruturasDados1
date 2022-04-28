#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

NoArvore* busca(NoArvore* raiz, int chave){
    if(raiz == NULL){
        return NULL;
    } else if(raiz->chave == chave){
        return raiz;
    } else if(raiz->chave < chave){
        return busca(raiz->dir, chave);
    } else {
        return busca(raiz->esq, chave);
    }
}

NoArvore* get_min(NoArvore* raiz){
    if (raiz == NULL){
        return NULL;
    }
    while(raiz->esq != NULL){
        raiz = raiz->esq;
    }
    return raiz;
}

int sucessor(NoArvore *raiz, int chave) {
    NoArvore* atual = busca(raiz, chave);
    if (atual == NULL){
        return -1;
    }
    if (atual->dir != NULL){
        NoArvore* resultado = get_min(atual->dir);
        if (resultado == NULL){
            return -1;
        } else {
            return resultado->chave; 
        }
    } else {
        NoArvore* sucessor = NULL;
        NoArvore* pai = raiz;
        while(pai != atual){
            if(atual->chave < pai->chave){
                sucessor = pai;
                pai = pai->esq;
            } else {
                pai = pai->dir;
            }
        }
        if (sucessor == NULL){
            return -1;
        } else {
            return sucessor->chave; 
        }
    }
}

NoArvore* get_max(NoArvore* raiz){
    if (raiz == NULL){
        return NULL;
    }
    while(raiz->dir != NULL){
        raiz = raiz->dir;
    }
    return raiz;
}

int antecessor(NoArvore *raiz, int chave) {
    NoArvore* antecessor = NULL;
    
    if (raiz == NULL){
        return -1;
    }

    while(1){
        if(chave < raiz->chave){
            raiz = raiz->esq;
        } else if (chave > raiz->chave){
            antecessor = raiz;
            raiz = raiz->dir;
        } else {
            if (raiz->esq){
                antecessor = get_max(raiz->esq);
            }
            break;
        }

        if (!raiz){
            return -1;
        }
    }
    if (antecessor == NULL){
        return -1;
    } else {
        return antecessor->chave;
    }
}