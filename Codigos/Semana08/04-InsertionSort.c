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

void insertion_sort(int *vetor, int tamanho){
    int i, k;
    for (i = 1; i < tamanho; i++){
        int item_atual = vetor[i];
        int indice_inserir = i;
        for (k = i - 1; k >= 0 && item_atual < vetor[k]; k--){
            vetor[k + 1] = vetor[k];
            indice_inserir--;
        }
        vetor[indice_inserir] = item_atual;
    }
}

void insertion_sort_decrescente(int *vetor, int tamanho){
    int i, k;
    for (i = 1; i < tamanho; i++){
        int item_atual = vetor[i];
        int indice_inserir = i;
        for (k = i - 1; k >= 0 && item_atual > vetor[k]; k--){
            vetor[k + 1] = vetor[k];
            indice_inserir--;
        }
        vetor[indice_inserir] = item_atual;
    }
}

int main(){

    srand(time(NULL));

    int tamanho = 10;

    int *vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);

    insertion_sort(vetor, tamanho);
    imprimir(vetor, tamanho);

    insertion_sort_decrescente(vetor, tamanho);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}