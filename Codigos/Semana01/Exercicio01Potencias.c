#include <stdio.h>

/* 
Melissa Junqueira de Barros Lins, 11201920583
*/

int calcula_potencia(int numero){
    int resto_divisao = 0;
    while (resto_divisao == 0){
        if (numero == 1){
            return 1;
        }
        resto_divisao = numero % 2;
        numero = numero / 2 ;
    } 
    return 0;
}

int main(){
    int quantidade_numeros;
    int quantidade_potencias = 0;
    scanf("%d", &quantidade_numeros);

    for (int i = 0; i < quantidade_numeros; i++){
        int numero;
        int eh_potencia;
        scanf("%d", &numero);

        eh_potencia = calcula_potencia(numero);

        if (eh_potencia == 1){
            quantidade_potencias++;
        }
    }

    printf("%d", quantidade_potencias);

}