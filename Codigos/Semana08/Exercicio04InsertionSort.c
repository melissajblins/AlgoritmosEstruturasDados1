#include <stdio.h>

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
   int data;
   DLinkedNode *prev, *next;
};

void troca_data(DLinkedNode *a, DLinkedNode *b){
    int temporario = a->data;
    a->data = b->data;
    b->data = temporario;
}

int compara(int a, int b, int *contador){
    *contador = *contador + 1;
    return(a > b);
}

DLinkedNode *insertion_sort(DLinkedNode *inicio, int *comparacoes) {
    *comparacoes = 0;
    int conta_comparacao = 0;

    DLinkedNode *proximo = inicio;
    DLinkedNode *anterior = NULL;
    while(proximo != NULL){
        anterior = proximo->next;
        while(anterior != NULL && anterior->prev != NULL && compara(anterior->prev->data, anterior->data, &conta_comparacao)){
            troca_data(anterior, anterior->prev);
            anterior = anterior->prev;
        }
        proximo = proximo->next;
    }

    *comparacoes = conta_comparacao;
    
    return inicio;
}