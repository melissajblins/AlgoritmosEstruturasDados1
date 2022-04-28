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
    // Impressao nao deve incluir espaco apos ultimo caractere
    // Deve ser incluido um \n ao final da impressao
}

void imprimir2(LinkedNode *inicio) {
    if(inicio != NULL){
        imprimir2(inicio->next);
        if (inicio->next == inicio){
            printf("%d\n", inicio->data);
        }else{
            printf("%d ", inicio->data);
        }
    }
    // Impressao nao deve incluir espaco apos ultimo caractere
    // Deve ser incluido um \n ao final da impressao
}