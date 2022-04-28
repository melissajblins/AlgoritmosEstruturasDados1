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

void r_counting_sort(int *v, int n, int base, int potencia) {
    int c[base];
    int i;
    for (i = 0; i < base; i++)
        c[i] = 0;
    int d;
    for (i = 0; i < n; i++) {
        d = (v[i] / potencia) % base;
        c[d]++;
    }
    for (i = 1; i < base; i++)
        c[i] += c[i - 1];
    int saida[n];
    for (i = n - 1; i >= 0; i--) {
        d = (v[i] / potencia) % base;
        saida[c[d] - 1] = v[i];
        c[d]--;
    }
    for (i = 0; i < n; i++)
        v[i] = saida[i];
}

void radixsort(int *v, int n, int n_digitos) {
    int i, potencia = 1;
    for (i = 0; i < n_digitos; i++) {
        r_counting_sort(v, n, 10, potencia);
        potencia *= 10;
    }
}

int main(){

    srand(time(NULL));

    int tamanho = 10;

    int *vetor = vetor_aleatorio(tamanho);
    imprimir(vetor, tamanho);

    radixsort(vetor, tamanho, 2);
    imprimir(vetor, tamanho);

    free(vetor);

    return 0;
}