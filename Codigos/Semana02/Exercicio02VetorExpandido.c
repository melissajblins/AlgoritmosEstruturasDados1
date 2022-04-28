#include <stdio.h>
#include <stdlib.h>

int* expandir_vetor(int *vetor, int n_compactado, int *n_expandido){
    int tamanho_vetor = 0;
    int posicao_atual = 0; 
    for (int i = 1; i < n_compactado; i += 2){
        tamanho_vetor += vetor[i];
    }

    int *vetor_expandido = malloc(sizeof(int) * tamanho_vetor);
    if (vetor_expandido == NULL){
        printf("Erro na alocação.\n");
        return vetor_expandido;
    }
    
    for (int i = 0; i < n_compactado; i += 2){
        for (int j = 0; j < vetor[i+1]; j++){
            vetor_expandido[posicao_atual] = vetor[i];
            posicao_atual++;
        }   
    }

    *n_expandido = tamanho_vetor;
    return vetor_expandido;
}

int main(){
    int vetor[6] = {10, 2, 1, 1, 2, 3};
    int tamanho_vetor_expandido = 0;

    expandir_vetor(vetor, 6, &tamanho_vetor_expandido);

    printf("%d", tamanho_vetor_expandido);

    return 0;
}