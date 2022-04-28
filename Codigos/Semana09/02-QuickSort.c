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

int particiona(int *v, int esq, int dir) {
    int pivo = v[dir];
    int i, ultimo_menores = esq-1;
    for (i = esq; i < dir; i++)
        if (v[i] < pivo) {
            ultimo_menores++;
            int tmp = v[i];
            v[i] = v[ultimo_menores];
            v[ultimo_menores] = tmp;
        }
    v[dir] = v[ultimo_menores+1];
    v[ultimo_menores+1] = pivo;
    return ultimo_menores+1;
}

// Ordena decrescente
int particiona_decrescente(int *v, int esq, int dir) {
    int pivo = v[dir];
    int i, ultimo_menores = esq-1;
    for (i = esq; i < dir; i++)
        if (v[i] > pivo) {
            ultimo_menores++;
            int tmp = v[i];
            v[i] = v[ultimo_menores];
            v[ultimo_menores] = tmp;
        }
    v[dir] = v[ultimo_menores+1];
    v[ultimo_menores+1] = pivo; 
    return ultimo_menores+1;
}

void quick_sort(int *v, int esq, int dir) {
    if (esq < dir) {
        int indice_pivo = particiona(v, esq, dir);
        quick_sort(v, esq, indice_pivo - 1);
        quick_sort(v, indice_pivo + 1, dir);
    }
}

void quicksort(int *v, int n) {
    quick_sort(v, 0, n - 1);
}

int main(){

    srand(time(NULL));

    int tamanho = 10;

    int *vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);

    quicksort(vetor, tamanho);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}