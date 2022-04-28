#include <stdio.h>

/* 
Melissa Junqueira de Barros Lins, 11201920583
*/

int quantidade_digitos(int numero){
    int numero_de_digitos = 0;
    while (numero > 0){
        numero = numero / 10;
        numero_de_digitos++;
    }

    return numero_de_digitos;
}