#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *vetor_aleatorio(int tamanho){
    int *vetor = malloc(sizeof(int) * tamanho);

    for (int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 100;
    }

    return vetor;
}

void imprimir(int *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void max_heapfy(int *v, int n, int i) {
    int esq = 2*i + 1;
    int dir = 2*i + 2;
    int maior = i;
    if (esq < n && v[esq] > v[maior])
        maior = esq;
    if (dir < n && v[dir] > v[maior])
        maior = dir;
    if (maior != i) {
        int aux = v[i];
        v[i] = v[maior];
        v[maior] = aux;
        max_heapfy(v, n, maior);
    }
}

void build_max_heap(int *v, int n) {
    int i;
    for (i = n/2 - 1; i >= 0; i--)
        max_heapfy(v, n, i);
}

void heapsort(int *vetor, int tamanho){
    build_max_heap(vetor, tamanho);
    int i;
    for (i = tamanho-1; i > 0; i--) {
        int aux = vetor[i];
        vetor[i] = vetor[0];
        vetor[0] = aux;
        max_heapfy(vetor, i, 0);
    }
}

int main(){

    srand(time(NULL));

    int tamanho = 10;

    int *vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);

    heapsort(vetor, tamanho);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}