#include <stdio.h>
#include <stdlib.h>

typedef struct ItemVetor ItemVetor;
struct ItemVetor {
    char *modelo;
    char *planeta;
    int autonomia;
};

int comparar(ItemVetor item1, ItemVetor item2);

void max_heapfy(ItemVetor *v, int n, int i, int *comparacoes) {
    int esq = 2*i + 1;
    int dir = 2*i + 2;
    int maior = i;
    if (esq < n){
        if (comparar(v[esq], v[maior]) > 0){
            maior = esq;
        }
        *comparacoes = *comparacoes + 1;
    }    
    if (dir < n){
        if (comparar(v[dir],v[maior]) > 0){
            maior = dir;
        }
        *comparacoes = *comparacoes + 1;
    }

    if (maior != i) {
        ItemVetor aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        max_heapfy(v, n, maior, comparacoes);
    }
}

void build_max_heap(ItemVetor *v, int n, int *comparacoes) {
    int i;
    for (i = n/2 - 1; i >= 0; i--)
        max_heapfy(v, n, i, comparacoes);
}

int heapsort(ItemVetor v[], int n) {
    int comparacoes = 0;
    build_max_heap(v, n, &comparacoes);
    int i;
    for (i = n-1; i > 0; i--) {
        ItemVetor aux = v[i];
        v[i] = v[0];
        v[0] = aux;
        max_heapfy(v, i, 0, &comparacoes);
    }
    
    return comparacoes;
}