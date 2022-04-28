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

void intercala(int *v, int esq_inicio, int esq_fim, int dir_fim) {
    int dir_inicio = esq_fim + 1;
    int esq = esq_inicio, dir = dir_inicio;
    int comp = dir_fim - esq_inicio + 1;
    int *v_aux = malloc(sizeof(int) * comp);
    int i;
    for (i = 0; i < comp; i++) {
        if (esq > esq_fim){
            v_aux[i] = v[dir++];
        }
        else if (dir > dir_fim)
            v_aux[i] = v[esq++];
        else if (v[esq] <= v[dir])
            v_aux[i] = v[esq++];
        else
            v_aux[i] = v[dir++];
    }
    for (i = 0; i < comp; i++)
        v[esq_inicio + i] = v_aux[i];
    free(v_aux);
}

// Ordena decrescente
void intercala_decrescente(int *v, int esq_inicio, int esq_fim, int dir_fim) {
    int dir_inicio = esq_fim + 1;
    int esq = esq_inicio, dir = dir_inicio;
    int comp = dir_fim - esq_inicio + 1;
    int *v_aux = malloc(sizeof(int) * comp);
    int i;
    for (i = 0; i < comp; i++) {
        if (esq > esq_fim){
            v_aux[i] = v[dir++];
        }
        else if (dir > dir_fim)
            v_aux[i] = v[esq++];
        else if (v[esq] >= v[dir])
            v_aux[i] = v[esq++];
        else
            v_aux[i] = v[dir++];
    }
    for (i = 0; i < comp; i++)
        v[esq_inicio + i] = v_aux[i];
    free(v_aux);
}

void merge_sort(int *v, int esq, int dir) {
    if (esq < dir) {
        int meio = (esq + dir) / 2;
        merge_sort(v, esq, meio);
        merge_sort(v, meio+1, dir);
        intercala(v, esq, meio, dir);
    }       
}

void mergesort(int *v, int n) {
    merge_sort(v, 0, n - 1);
}

int main(){
    srand(time(NULL));

    int tamanho = 10;

    int *vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);

    mergesort(vetor, tamanho);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}