#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

typedef struct DLinkedNode DLinkedNode;
struct DLinkedNode {
   int data;
   DLinkedNode *next, *prev;
};

void duplicar_pares1(LinkedNode *inicio) {
    LinkedNode *atual = inicio;
    while(atual != NULL){
        if (atual->next != NULL && atual->data%2 == 0){
            LinkedNode *novo = malloc(sizeof(LinkedNode));
            novo->data = atual->data;
            novo->next = atual->next;
            atual->next = novo;
            atual = atual->next->next;
        } else if (atual->next == NULL && atual->data%2 == 0){
            LinkedNode *novo = malloc(sizeof(LinkedNode));
            novo->data = atual->data;
            novo->next = NULL;
            atual->next = novo;
            atual = atual->next->next;
        } else {
            atual = atual->next;
        }
        
    }
}

void duplicar_pares2(DLinkedNode *inicio) {
    DLinkedNode *atual = inicio;
    while(atual != NULL){
        if (atual->next != NULL && atual->data%2 == 0){
            DLinkedNode *novo = malloc(sizeof(DLinkedNode));
            novo->data = atual->data;
            novo->next = atual->next;
            atual->next->prev = novo;
            atual->next = novo;
            novo->prev = atual;
            atual = atual->next->next;
        } else if (atual->next == NULL && atual->data%2 == 0){
            DLinkedNode *novo = malloc(sizeof(DLinkedNode));
            novo->data = atual->data;
            novo->next = NULL;
            atual->next = novo;
            novo->prev = atual;
            atual = atual->next->next;
        } else {
            atual = atual->next;
        }
    }
}

int main(){

    LinkedNode item1;
    item1.data = 1;

    LinkedNode item2;
    item2.data = 2;

    LinkedNode item3;
    item3.data = 3;

    LinkedNode item4;
    item4.data = 4;
    
    LinkedNode item5;
    item5.data = 5;

    LinkedNode item6;
    item6.data = 6;

    LinkedNode item7;
    item7.data = 7;

    LinkedNode item8;
    item8.data = 8;

    LinkedNode item9;
    item9.data = 9;

    item1.next = &item2;
    item2.next = &item3;
    item3.next = &item4;
    item4.next = &item5;
    item5.next = &item6;
    item6.next = &item7;
    item7.next = &item8;
    item8.next = &item9;
    item9.next = NULL;

    duplicar_pares2(&item1);

    LinkedNode *atual = &item1;
    while(atual != NULL){
        printf("%d ", atual->data);
        atual = atual->next;
    }

    return 0;
}