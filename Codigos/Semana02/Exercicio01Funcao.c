#include <stdio.h>

void funcao(int a, int b, int *resultado){
    for (int i = 1; i <= a; i++){
        int somatorio = 0;
        for (int j = 1; j <= b; j++){
            somatorio += ((i*j) + 10);
        }
        *resultado += (somatorio * 5 * i);
    }

    return;
}

int main(){
    int resultado = 0;
    int a = 2;
    int b = 3;

    funcao(a, b, &resultado);

    printf("%d", resultado);

    return 0;
}