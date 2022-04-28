#include <stdlib.h>
#include <string.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    char *chave;
    NoArvore *esq, *dir;
};

int CmpStr(const char *a, const char *b){
    return (strcmp (a, b));
}

NoArvore *buscar(NoArvore *raiz, char *chave) {
    int resultado;
    if(raiz != NULL){
        resultado = CmpStr(chave, raiz->chave);
        if (resultado < 0){
            buscar(raiz->esq, chave);
        } else if (resultado > 0){
            buscar(raiz->dir, chave);
        } else {
            return raiz;
        }
    } else {
        return NULL;
    }
}

NoArvore *inserir(NoArvore *raiz, char *chave_nova) {
    NoArvore* novo_no =  malloc(sizeof(NoArvore));
    novo_no->chave = malloc(strlen(chave_nova) + 1);
    strcpy(novo_no->chave, chave_nova);
    novo_no->esq = NULL;
    novo_no->dir = NULL;

    NoArvore* x = raiz;
    NoArvore* y = NULL;

    while(x != NULL){
        y = x;
        if ((CmpStr(chave_nova, x->chave)) < 0){
            x = x->esq;
        } else {
            x = x->dir;
        }
    }
    if (y == NULL){
        y = novo_no;
        raiz = y;
    } else if ((CmpStr(chave_nova, y->chave)) < 0){
        y->esq = novo_no;
    } else {
        y->dir = novo_no;
    }
    return raiz;
}

NoArvore *remover(NoArvore *raiz, char *chave) {
    NoArvore* atual = raiz;
    NoArvore* anterior = NULL;

    while(atual != NULL && (CmpStr(chave, atual->chave)) != 0){
        anterior = atual;
        if ((CmpStr(chave, atual->chave)) < 0){
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    if (atual == NULL){
        return raiz;
    }

    if (atual->esq == NULL || atual->dir == NULL){
        NoArvore* novo_atual;
        if (atual->esq == NULL){
            novo_atual = atual->dir;
        } else {
            novo_atual = atual->esq;
        }
        if (anterior == NULL){
            return novo_atual;
        }

        if (atual == anterior->esq){
            anterior->esq = novo_atual;
        } else {
            anterior->dir = novo_atual;
        }

        free(atual->chave);
        free(atual);
    } else {
       NoArvore* pai = NULL;
       NoArvore* temporario;

       temporario = atual->dir;
       while(temporario->esq != NULL){
           pai = temporario;
           temporario = temporario->esq;
       } 
        if (pai != NULL){
            pai->esq = temporario->dir;
        } else {
            atual->dir = temporario->dir;
        }

        atual->chave = temporario->chave;
        free(temporario);
    }
    return raiz;
}

void liberar_arvore(NoArvore *raiz) {
    if(raiz != NULL){
        liberar_arvore(raiz->esq);
        liberar_arvore(raiz->dir);
        free(raiz->chave);
        free(raiz);
    }
}