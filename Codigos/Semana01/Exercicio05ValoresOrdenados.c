#include <stdio.h>

/* 
Melissa Junqueira de Barros Lins, 11201920583
*/

void imprimir_maior_sequencia(int vetorUsuario[], int tamanhoDoVetor){
    int vetorSequencia[tamanhoDoVetor];
    int indice_maior;
    int quantidade_maior;
    for(int i = 0; i < tamanhoDoVetor; i++){
        int tamanhoDaSequencia = 0;
        for(int j = (i + 1); j < tamanhoDoVetor; j++){
            int k = (j - 1);
            if ((vetorUsuario[j] - vetorUsuario[k]) > 0){
                tamanhoDaSequencia++;
            } 
            else {
               vetorSequencia[i] = tamanhoDaSequencia;
               j = tamanhoDoVetor;
            }
            
            if (j == (tamanhoDoVetor - 1)){
                vetorSequencia[i] = tamanhoDaSequencia;
            }
            
        }
    }

    vetorSequencia[tamanhoDoVetor - 1] = 0;

    for (int i = 0; i < tamanhoDoVetor; i++){
        if (i == 0){
            indice_maior = i;
            quantidade_maior = vetorSequencia[i];
        } else {
                if (vetorSequencia[i] > quantidade_maior){
                    indice_maior = i;
                    quantidade_maior = vetorSequencia[i];
                }
        }
    } 
    
    for (int i = indice_maior; i < (indice_maior + quantidade_maior + 1); i++){
        if (i < tamanhoDoVetor){
            printf("%d ", vetorUsuario[i]);
        }
    }
    
    return;
}

int main(){
   int tamanhoDoVetor = 0;
   scanf("%d", &tamanhoDoVetor);
   
   int vetorUsuario[tamanhoDoVetor];

    for(int i = 0; i < tamanhoDoVetor; i++){
        scanf("%d", &vetorUsuario[i]);
    }

    imprimir_maior_sequencia(vetorUsuario, tamanhoDoVetor);

   return 0;
}