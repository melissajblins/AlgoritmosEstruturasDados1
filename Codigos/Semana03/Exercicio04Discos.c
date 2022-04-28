#include <stdio.h>
#include <stdlib.h>

typedef struct DiscoVoador DiscoVoador;
struct DiscoVoador {
    char *modelo;
    char *planeta;
    int autonomia;
};

int verificar_ordenacao(DiscoVoador *discos, int n_discos) {
    // Caso 1
    int conta_modelo_ordenado = 0;
    for (int i = 0; i < (n_discos - 1); i++){
        if (discos[i].modelo[5] <= discos[i+1].modelo[5]){
            conta_modelo_ordenado++;
        } else {
            break;
        }
        if (conta_modelo_ordenado == (n_discos -1)){
            return 1;
        }
    }
    
    // Caso 2
    conta_modelo_ordenado = 0;
    for (int i = 0; i < (n_discos - 1); i++){
        if (discos[i].modelo[5] >= discos[i+1].modelo[5]){
            conta_modelo_ordenado++;
        } else {
            break;
        }
        if (conta_modelo_ordenado == (n_discos - 1)){
            return 2;
        }
    }

    // Caso 3
    int conta_planeta_ordenado = 0;
    for (int i = 0; i < (n_discos - 1); i++){
        if (discos[i].planeta[0] <= discos[i+1].planeta[0]){
            conta_planeta_ordenado++;
        } else {
            break;
        }
        if (conta_planeta_ordenado == (n_discos - 1)){
            return 3;
        }
    }

    // Caso 3
    int conta_autonomia = 0;
    for (int i = 0; i < (n_discos - 1); i++){
        if (discos[i].autonomia <= discos[i+1].autonomia){
            conta_autonomia++;
        } else {
            break;
        }
        if (conta_autonomia == (n_discos - 1)){
            return 4;
        }
    }

    return 0;
}