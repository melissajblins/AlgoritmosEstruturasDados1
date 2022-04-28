#include <stdio.h>
#include <stdlib.h>

void *quantidade_discos(char **discos, int n_discos, int **quantidade_por_fabricante){
    int *vetor_quantidade = malloc(sizeof(int) * 4);
    for (int i = 0; i < n_discos; i++){
        if (discos[i][7]  == 65){
            (vetor_quantidade)[0] = (vetor_quantidade)[0] + 1;
        } else if (discos[i][7]  == 66){
            (vetor_quantidade)[1] = (vetor_quantidade)[1] + 1;
        } else if (discos[i][7]  == 67){
            (vetor_quantidade)[2] = (vetor_quantidade)[2] + 1;
        } else {
            (vetor_quantidade)[3] = (vetor_quantidade)[3] + 1;
        }
    }
    *quantidade_por_fabricante = vetor_quantidade;
}

        int main(){

            int **m;
            m = malloc(sizeof(char*)*8);
            int i;
            for (i; i< 8; i++){
                m[i] = malloc(sizeof(char*)*8);
            }

            m[0]="Modelo_A1";
            m[1]="Modelo_A2";
            m[2]="Modelo_B1";
            m[3]="Modelo_B2";
            m[4]="Modelo_B3";
            m[5]="Modelo_C1";
            m[6]="Modelo_D1";
            m[7]="Modelo_D2";

            int **quantidade;
            quantidade = malloc(sizeof(int*)*4);
                for (i; i< 4; i++){
                m[i] = malloc(sizeof(int*)*1);
            }

            quantidade_discos(m, 8, quantidade);
            return 0;
        }