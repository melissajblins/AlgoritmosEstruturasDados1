#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

LinkedNode* inverter_lista(LinkedNode *inicio) {
    if (inicio == NULL){
        return inicio;
    }
    
    LinkedNode *atual = inicio;
    LinkedNode *anterior = NULL;
    LinkedNode *proximo = NULL;
    while(atual != NULL){
        proximo = atual->next;
        atual->next = anterior;
        anterior = atual;
        atual = proximo; 
    }
    inicio = anterior;
}