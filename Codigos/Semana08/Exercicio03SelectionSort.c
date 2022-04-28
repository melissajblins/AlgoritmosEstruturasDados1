#include <stdio.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

void troca_data(LinkedNode *a, LinkedNode *b){
    int temporario = a->data;
    a->data = b->data;
    b->data = temporario;
}

LinkedNode *selection_sort(LinkedNode *inicio, int *trocas, int *comparacoes) {
    *trocas = 0;
    *comparacoes = 0;
    
    LinkedNode *auxiliar = inicio;
    LinkedNode *temporario = NULL;
    LinkedNode *no = NULL;

    while(auxiliar != NULL){
        no = auxiliar;
        temporario = auxiliar->next;
        while(temporario != NULL){
            if(no->data > temporario->data){
                no = temporario;
            }
            *comparacoes = *comparacoes + 1;
            temporario = temporario->next;
        }
        if(auxiliar->data > no->data){
            troca_data(auxiliar, no);
            *trocas = *trocas + 1;
        }
        auxiliar = auxiliar->next;
    }

    return inicio;
}

