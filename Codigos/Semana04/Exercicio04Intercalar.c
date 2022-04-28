#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

LinkedNode* intercalar_listas(LinkedNode *inicio1, LinkedNode *inicio2) {
    if (inicio1 == NULL && inicio2 == NULL){
        return inicio1;
    }
    
    if (inicio1 == NULL){
        return inicio2;
    }
    
    if (inicio2 == NULL){
        return inicio1;
    }

    LinkedNode *no_inicial = NULL;


    if(inicio1->data <= inicio2->data){
        no_inicial = inicio1;
        inicio1 = inicio1->next;
    } else {
        no_inicial = inicio2;
        inicio2 = inicio2->next;   
    }
    
    LinkedNode *no_temporario = no_inicial; 
        
    while(inicio1 != NULL && inicio2 != NULL){
        LinkedNode *temporario = NULL;
        if (inicio1->data <= inicio2->data){
            temporario = inicio1;
            inicio1 = inicio1->next;
        }else {
            temporario = inicio2;
            inicio2 = inicio2->next;   
        }
        no_temporario->next = temporario;
        no_temporario = temporario;
    }

    if (inicio1 != NULL) {
        no_temporario->next = inicio1;
    } else if (inicio2 != NULL) {
        no_temporario->next = inicio2;
    }

    return no_inicial;
}