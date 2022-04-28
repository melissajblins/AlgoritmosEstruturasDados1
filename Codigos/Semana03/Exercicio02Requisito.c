#include <stdlib.h>

typedef struct Disciplina Disciplina;
struct Disciplina {
    int cod;
    char *nome;
    int creditos;
    Disciplina *requisito;
};

Disciplina *requisito_inicial(Disciplina *disciplina, int *qtd) {
    Disciplina *disciplina_inicial_dados = NULL;
    while (disciplina->requisito != NULL){
        *qtd = *qtd + 1;
        disciplina = disciplina->requisito;
    }
    disciplina_inicial_dados = disciplina;
    
    if (*qtd == 0){
        return NULL;
    }
    return disciplina_inicial_dados;
}