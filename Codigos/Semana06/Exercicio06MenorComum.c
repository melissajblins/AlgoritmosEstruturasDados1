#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    NoArvore *esq, *dir;
};

NoArvore *inserir_arvore(NoArvore *raiz, int chave_nova) {
    if (raiz == NULL) {
        NoArvore *novo_no = malloc(sizeof(NoArvore));
        novo_no->chave = chave_nova;
        novo_no->esq = NULL;
        novo_no->dir = NULL;
        return novo_no;
    }
    if (chave_nova < raiz->chave){
        raiz->esq = inserir_arvore(raiz->esq, chave_nova);
    } else if (chave_nova > raiz->chave){
        raiz->dir = inserir_arvore(raiz->dir, chave_nova);
    }
    return raiz;
}

int get_min(NoArvore *raiz){
    if (raiz == NULL){
        return -1;
    }
    if(raiz->esq == NULL){
        return raiz->chave;
    } else {
        return get_min(raiz->esq);
    }
}

void limpar_arvore(NoArvore *raiz) {
    if (raiz == NULL) return;
    limpar_arvore(raiz->esq);
    limpar_arvore(raiz->dir);
    free(raiz);
}

int buscar(NoArvore *raiz2, int chave){
    if (raiz2 == NULL){
        return 0;
    }
    if (raiz2->chave == chave){
        return chave;
    }else if (chave < raiz2->chave){
        return buscar(raiz2->esq, chave);
    } else {
        return buscar(raiz2->dir, chave);
    }
}

NoArvore *percorre(NoArvore *raiz1, NoArvore *raiz2, NoArvore *tree){
    if (raiz1 == NULL){
        return tree;
    }

    if(buscar(raiz2, raiz1->chave) == raiz1->chave){
        tree = inserir_arvore(tree, raiz1->chave);
    }
    tree = percorre(raiz1->esq, raiz2, tree);
    return percorre(raiz1->dir, raiz2, tree);

}

int menor_chave_comum(NoArvore *raiz1, NoArvore *raiz2) {
    NoArvore *tree = NULL;
    tree = percorre(raiz1, raiz2, tree);
    int resultado = get_min(tree);
    limpar_arvore(tree);
    return resultado;
}
