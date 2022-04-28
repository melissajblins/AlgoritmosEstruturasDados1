#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

int buscar(NoArvore *raiz2, int chave){
    if (raiz2 == NULL){
        return 0;
    }
    if (raiz2->chave == chave){
        return 1;
    }else if (chave < raiz2->chave){
        return buscar(raiz2->esq, chave);
    } else {
        return buscar(raiz2->dir, chave);
    }
}

int percorre(NoArvore *raiz1, NoArvore *raiz2, int quantidade){
    if (raiz1 == NULL){
        return quantidade;
    }

    if(buscar(raiz2, raiz1->chave)){
     quantidade ++;    
    }
    
    quantidade = percorre(raiz1->esq, raiz2, quantidade);
    return percorre(raiz1->dir, raiz2, quantidade);

}

int qtd_chaves_comuns(NoArvore *raiz1, NoArvore *raiz2) {
    int quantidade = 0; 
    return percorre(raiz1, raiz2, quantidade);
}
