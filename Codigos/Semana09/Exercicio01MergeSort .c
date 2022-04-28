#include <stdio.h>
#include <stdlib.h>

void imprimir(int *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++){
        if (i != (tamanho - 1)){
            printf("%d ", vetor[i]);
        } else {
            printf("%d", vetor[i]);
        }
    }
    printf("\n");
}

int compara(int a, int b, int *contador){
    *contador = *contador + 1;
    return(a >= b);
}

void intercala(int *v, int esq_inicio, int esq_fim, int dir_fim, int *contador) {
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
        else if (compara(v[dir], v[esq], contador))
            v_aux[i] = v[esq++];
        else
            v_aux[i] = v[dir++];
    }
    for (i = 0; i < comp; i++)
        v[esq_inicio + i] = v_aux[i];
    free(v_aux);
}

void merge_sort(int *v, int esq, int dir, int *contador) {
    if (esq < dir) {
        int meio = (esq + dir) / 2;
        merge_sort(v, esq, meio, contador);
        merge_sort(v, meio+1, dir, contador);
        intercala(v, esq, meio, dir, contador);
    }       
}

void mergesort(int *v, int n, int *contador) {
    merge_sort(v, 0, n - 1, contador);
}

int main(){
    int tamanho, contador = 0;
    scanf("%d", &tamanho);
    int vetor[tamanho];

    for (int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }

    mergesort(vetor, tamanho, &contador);

    imprimir(vetor, tamanho);

    printf("Comparacoes: %d\n", contador);

    return 0;
}