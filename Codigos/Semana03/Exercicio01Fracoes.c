#include <stdio.h>

typedef struct Fracao Fracao;
struct Fracao {
    int numerador, denominador;
};

int MDC(int numerador, int denominador){
    if (denominador == 0){
        return numerador;
    } else {
        return MDC(denominador, (numerador % denominador));
    }
}

Fracao somar(Fracao f1, Fracao f2) {
    Fracao soma;
    int numerador1 = 0;
    int numerador2 = 0;
    if (f1.denominador == f2.denominador){
        soma.numerador = (f1.numerador + f2.numerador);
        soma.denominador = f1.denominador;
    } else {
        soma.denominador = (f1.denominador * f2.denominador);
        numerador1 = ((soma.denominador / f1.denominador) * f1.numerador);
        numerador2 = ((soma.denominador / f2.denominador) * f2.numerador);
        soma.numerador = numerador1 + numerador2;
    }

    int maximo_divisor = MDC(soma.numerador, soma.denominador);
    soma.numerador = soma.numerador/maximo_divisor;
    soma.denominador = soma.denominador/maximo_divisor;

    return soma;
}

Fracao somar_vetor(Fracao f[], int n_fracoes) {
    Fracao soma = {0,0};
    for (int i = 0; i < n_fracoes; i++){
        if (i == 0){
            soma.numerador = f[i].numerador;
            soma.denominador = f[i].denominador;
        } else {
            soma = somar(soma, f[i]);
        }
    }

    return soma;
}

Fracao multiplicar(Fracao f1, Fracao f2) {
    Fracao multiplica;
    multiplica.numerador = (f1.numerador * f2.numerador);
    multiplica.denominador = (f1.denominador * f2.denominador);    

    int maximo_divisor = MDC(multiplica.numerador, multiplica.denominador);
    multiplica.numerador = multiplica.numerador/maximo_divisor;
    multiplica.denominador = multiplica.denominador/maximo_divisor;

    return multiplica;
}

Fracao multiplicar_vetor(Fracao f[], int n_fracoes) {
    Fracao multiplica = {1,1};
    for (int i = 0; i < n_fracoes; i++){
        multiplica = multiplicar(multiplica, f[i]);
    }

    return multiplica;
}