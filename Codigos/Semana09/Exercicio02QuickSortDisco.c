#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Disco Disco;
struct Disco {
   int codigo;
   double preco;
};

int compara(int a, int b, int *contador){
    *contador = *contador + 1;
    return(a > b);
}

int compara_preco(Disco a, Disco b, int *contador){
    *contador = *contador + 1;
    if(a.preco == b.preco){
        return(a.codigo > b.codigo);
    } else{
        return(a.preco > b.preco); 
    }
}

int particiona(Disco *v, int esq, int dir, int *contador) {
    Disco pivo = v[dir];
    int i, ultimo_menores = esq-1;
    for (i = esq; i < dir; i++)
        if (compara(pivo.codigo, v[i].codigo, contador)) {
            ultimo_menores++;
            Disco tmp = v[i];
            v[i] = v[ultimo_menores];
            v[ultimo_menores] = tmp;
        }
    v[dir] = v[ultimo_menores+1];
    v[ultimo_menores+1] = pivo;
    return ultimo_menores+1;
}

int particiona_decrescente(Disco *v, int esq, int dir, int *contador) {
    Disco pivo = v[dir];
    int i, ultimo_menores = esq-1;
    for (i = esq; i < dir; i++)
        if (compara(v[i].codigo, pivo.codigo, contador)) {
            ultimo_menores++;
            Disco tmp = v[i];
            v[i] = v[ultimo_menores];
            v[ultimo_menores] = tmp;
        }
    v[dir] = v[ultimo_menores+1];
    v[ultimo_menores+1] = pivo; 
    return ultimo_menores+1;
}

int particiona_preco(Disco *v, int esq, int dir, int *contador) {
    Disco pivo = v[dir];
    int i, ultimo_menores = esq-1;
    for (i = esq; i < dir; i++)
        if (compara_preco(pivo, v[i], contador)) {
            ultimo_menores++;
            Disco tmp = v[i];
            v[i] = v[ultimo_menores];
            v[ultimo_menores] = tmp;
        }
    v[dir] = v[ultimo_menores+1];
    v[ultimo_menores+1] = pivo;
    return ultimo_menores+1;
}

void quick_sort(Disco *v, int esq, int dir, int *tipo, int*contador) {
    int indice_pivo;
    if (esq < dir) {
        if (*tipo == 1){
            indice_pivo = particiona(v, esq, dir, contador);
        } else if (*tipo == 2){
            indice_pivo = particiona_decrescente(v, esq, dir, contador);
        } else {
            indice_pivo = particiona_preco(v, esq, dir, contador); 
        }
        quick_sort(v, esq, indice_pivo - 1, tipo, contador);
        quick_sort(v, indice_pivo + 1, dir, tipo, contador);
    }
}

int quicksort(Disco *v, int n, int tipo) {
    int contador = 0;
    quick_sort(v, 0, n - 1, &tipo, &contador);

    return contador;
}