#include <stdio.h>

int main(){
    int numero = 23; // Inicializando a variável numero
    int *ponteiro = &numero; // Inicializando o ponteiro

    printf("%d", *ponteiro); // Imprimindo o valor da 
                             //variável para a qual o ponteiro aponta
    
    return 0;
}
