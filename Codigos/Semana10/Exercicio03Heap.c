#include <stdio.h>
#include <stdlib.h>

int eh_heap_maximo(int vetor[], int tamanho){
    int i = 0;
    for (i; i < (tamanho - 2)/2; i++){
        if(vetor[2 * i + 1] > vetor[i] && tamanho > 2 * i + 1){
            return -1;
        }
        if (tamanho > 2 * i + 2 && vetor[2 * i + 2] > vetor[i]){
            return -1;
        }
    }
    return 1;
}

int eh_heap_minimo(int vetor[], int tamanho){
    int i = 0;
    if (tamanho <= 1){
        return 1;
    }

    for(i; i < (tamanho - 2)/2; i++){
        if(vetor[i] > vetor[2 * i + 1] || (tamanho != 2 * i + 2 && vetor[i] > vetor[2 * i + 2])){
            return -1;
        }
    }
    return 1;
}

int main() {
    int tamanho;
    scanf("%d", &tamanho);

    int vetor[tamanho];
    for (int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }

    if(eh_heap_maximo(vetor, tamanho) == 1){
        printf("2\n");
    } else {
        if (eh_heap_minimo(vetor, tamanho) == 1){
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    return 0;
}