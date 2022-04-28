#include <stdio.h>

/* 
Melissa Junqueira de Barros Lins, 11201920583
*/

int valor_frequente(int v[], int n){
    int vetor_quantidade[n];
    int indice_maior;
    int quantidade_maior;
    for (int i = 0; i < n; i++){
        int conta_frequencia = 0;
        for (int j = 0; j < n; j++){
            if (v[i] == v[j]){
                conta_frequencia++;
            }
        }

        vetor_quantidade[i] = conta_frequencia;
    }

    for (int i = 0; i < n; i++){
        if (i == 0){
            indice_maior = i;
            quantidade_maior = vetor_quantidade[i];
        } else {
                if (vetor_quantidade[i] > quantidade_maior){
                    indice_maior = i;
                    quantidade_maior = vetor_quantidade[i];
                }
        }

    }

    return("%d", v[indice_maior]);

}

int main(){
    int vetor[20] = {1, 2, 3, 100, 22, 11, 11, 11, 3, 2, 1, 2, 50, 50, 50, 2, 99, 20, 60, 90};
    valor_frequente(vetor, 20);
    
    return 0;
}