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

int *vetor_ordenado(int tamanho){
    int *vetor = malloc(sizeof(int) * tamanho);

    for (int i = 0; i < tamanho; i++){
        vetor[i] = 1;
    }

    return vetor;
}

int *vetor_ordenado_decrescente(int tamanho){
    int *vetor = malloc(sizeof(int) * tamanho);

    for (int i = 0; i < tamanho; i++){
        vetor[i] = tamanho - i;
    }

    return vetor;
}

void imprimir(int *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int compara(int a, int b, int *contador){
    *contador = *contador + 1;
    return(a > b);
}

int compara_decrescente(int a, int b){
    return(a < b);
}

int selection_sort(int *vetor, int tamanho){
    int i, contador = 0;
    for (i = 0; i < tamanho - 1; i++){
        int indice_menor = i;
        int k;
        for (k = i + 1; k < tamanho; k++){
            if (compara(vetor[indice_menor], vetor[k], &contador)){
                indice_menor = k;
            }
        }
        if(indice_menor != i){
            int temporario = vetor[i];
            vetor[i] = vetor[indice_menor];
            vetor[indice_menor] = temporario;
        }
    }
    return contador;
}

int bubble_sort_otimizado(int *vetor, int tamanho){
    int i, k, trocou = 1, contador = 0;
    for (i = 0; i < tamanho - 1 && trocou; i++){
        trocou = 0;
        for (k = 0; k < tamanho - 1 - i; k++){
            if(compara(vetor[k], vetor[k + 1], &contador)){
                int temporario = vetor[k];
                vetor[k] = vetor[k + 1];
                vetor[k + 1] = temporario;
                trocou = 1;
            }
        }
    }
    return contador;
}

int insertion_sort(int *vetor, int tamanho){
    int i, k, contador = 0;
    for (i = 1; i < tamanho; i++){
        int item_atual = vetor[i];
        int indice_inserir = i;
        for (k = i - 1; k >= 0 && compara(vetor[k], item_atual, &contador); k--){
            vetor[k + 1] = vetor[k];
            indice_inserir--;
        }
        vetor[indice_inserir] = item_atual;
    }
    return contador;
}

int main(){

    srand(time(NULL));

    int tamanho = 10;

    int *vetor = NULL;

    // Selection Sort
    printf("\n+++ Selection Sort +++\n");
    vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);
    int contador = selection_sort(vetor, tamanho);
    imprimir(vetor, tamanho);
    printf("\nNúmero de comparações: %d\n", contador);
    free(vetor);

    // Bubble Sort
    printf("\n+++ Bubble Sort +++\n");
    vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);
    contador = bubble_sort_otimizado(vetor, tamanho);
    imprimir(vetor, tamanho);
    printf("\nNúmero de comparações: %d\n", contador);
    free(vetor);

    // Insertion Sort
    printf("\n+++ Insertion Sort +++\n");
    vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);
    contador = insertion_sort(vetor, tamanho);
    imprimir(vetor, tamanho);
    printf("\nNúmero de comparações: %d\n", contador);
    free(vetor);

    return 0;
}