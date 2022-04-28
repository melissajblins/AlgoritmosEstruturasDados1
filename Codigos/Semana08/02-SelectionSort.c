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

void selection_sort(int *vetor, int tamanho){
    int i;
    for (i = 0; i < tamanho - 1; i++){
        int indice_menor = i;
        int k;
        for (k = i + 1; k < tamanho; k++){
            if (vetor[k] < vetor[indice_menor]){
                indice_menor = k;
            }
        }
        if(indice_menor != i){
            int temporario = vetor[i];
            vetor[i] = vetor[indice_menor];
            vetor[indice_menor] = temporario;
        }
    }
}

void selection_sort_decrescente(int *vetor, int tamanho){
    int i;
    for (i = 0; i < tamanho - 1; i++){
        int indice_maior = i;
        int k;
        for (k = i + 1; k < tamanho; k++){
            if (vetor[k] > vetor[indice_maior]){
                indice_maior = k;
            }
        }
        if(indice_maior != i){
            int temporario = vetor[i];
            vetor[i] = vetor[indice_maior];
            vetor[indice_maior] = temporario;
        }
    }
}

int main(){

    srand(time(NULL));

    int tamanho = 10;

    int *vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);

    selection_sort(vetor, tamanho);
    imprimir(vetor, tamanho);

    selection_sort_decrescente(vetor, tamanho);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}