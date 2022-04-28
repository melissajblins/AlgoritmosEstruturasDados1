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

void bubble_sort(int *vetor, int tamanho){
    int i, k;
    for (i = 0; i < tamanho - 1; i++){
        for (k = 0; k < tamanho - 1 - i; k++){
            if(vetor[k] > vetor[k + 1]){
                int temporario = vetor[k];
                vetor[k] = vetor[k + 1];
                vetor[k + 1] = temporario;
            }
        }
    }
}

void bubble_sort_otimizado(int *vetor, int tamanho){
    int i, k, trocou = 1;
    for (i = 0; i < tamanho - 1 && trocou; i++){
        trocou = 0;
        for (k = 0; k < tamanho - 1 - i; k++){
            if(vetor[k] > vetor[k + 1]){
                int temporario = vetor[k];
                vetor[k] = vetor[k + 1];
                vetor[k + 1] = temporario;
                trocou = 1;
            }
        }
    }
}

void bubble_sort_decrescente(int *vetor, int tamanho){
    int i, k;
    for (i = 0; i < tamanho - 1; i++){
        for (k = 0; k < tamanho - 1 - i; k++){
            if(vetor[k] < vetor[k + 1]){
                int temporario = vetor[k];
                vetor[k] = vetor[k + 1];
                vetor[k + 1] = temporario;
            }
        }
    }
}

void bubble_sort_decrescente_otimizado(int *vetor, int tamanho){
    int i, k, trocou = 1;
    for (i = 0; i < tamanho - 1 && trocou; i++){
        trocou = 0;
        for (k = 0; k < tamanho - 1 - i; k++){
            if(vetor[k] < vetor[k + 1]){
                int temporario = vetor[k];
                vetor[k] = vetor[k + 1];
                vetor[k + 1] = temporario;
                trocou = 1;
            }
        }
    }
}

int main(){

    srand(time(NULL));

    int tamanho = 10;

    int *vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);

    bubble_sort_otimizado(vetor, tamanho);
    imprimir(vetor, tamanho);

    bubble_sort_decrescente_otimizado(vetor, tamanho);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}