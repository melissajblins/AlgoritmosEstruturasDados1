#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};


void contar(LinkedNode *inicio, int *qtd, int *soma) {
    *soma = 0;
    *qtd = 0;
    LinkedNode *atual = inicio;
    while(atual != NULL){
        *qtd = *qtd + 1;
        *soma = *soma + atual->data;
        atual = atual->next;
    }
}

void imprimir1(LinkedNode *inicio) {
    LinkedNode *atual = inicio;
    while(atual != NULL){
        if (atual->next == NULL){
            printf("%d", atual->data);
        }else{
            printf("%d ", atual->data);
        }
        atual=atual->next;
    }
    printf("\n");
}

void imprimir2(LinkedNode *inicio) {
    LinkedNode *anterior = NULL;
    LinkedNode *atual = inicio;
    LinkedNode *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->next;
        atual->next = anterior;
        anterior = atual;
        atual = proximo;
    }
    inicio = anterior;

    atual = inicio;
    
    while(atual != NULL){
        if (atual->next == NULL){
            printf("%d\n", atual->data);
        } else{
            printf("%d ", atual->data);
        }
        atual = atual->next;
    }
}