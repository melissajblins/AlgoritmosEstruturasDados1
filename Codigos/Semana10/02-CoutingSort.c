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

void countingsort(int *v, int n, int k) {
    int c[k + 1];
    int i;
    for (i = 0; i < k + 1; i++)
        c[i] = 0;
    for (i = 0; i < n; i++)
        c[v[i]]++;
    for (i = 1; i < k + 1; i++)
        c[i] += c[i - 1];
    int saida[n];
    int atual;
    for (i = n - 1; i >= 0; i--) {
        atual = v[i];
        saida[c[atual] - 1] = atual;
        c[atual]--;
    }
    for (i = 0; i < n; i++)
        v[i] = saida[i];
}

int main(){

    srand(time(NULL));

    int tamanho = 10;

    int *vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);

    countingsort(vetor, tamanho, 99);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}