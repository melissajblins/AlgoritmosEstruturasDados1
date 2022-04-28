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

void shell_sort(int *vetor, int tamanho){
    int h = 1;
    while(h < tamanho/3){
        h = 3 * h + 1;
    }
    
    while(h >= 1){
        int i, k;
        for (i = h; i < tamanho; i++){
            int item_atual = vetor[i];
            int indice_inserir = i;
            for (k = i - h; k >= 0 && item_atual < vetor[k]; k-= h){
                vetor[k + h] = vetor[k];
                indice_inserir-=h;
            }
            vetor[indice_inserir] = item_atual;
        }
        h = h / 3;
    }
}

int main(){

    srand(time(NULL));

    int tamanho = 10;

    int *vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);

    shell_sort(vetor, tamanho);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}