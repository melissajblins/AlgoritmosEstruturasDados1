#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

int verificar_lista(LinkedNode *lista) {
    LinkedNode *temporario = lista;
    PilhaDinamica *pilha = criar_pilha();

    while(temporario != NULL){
        push(pilha, temporario->data);
        temporario = temporario->next;
    }

    while(lista != NULL){
        int topo = pilha->topo;
        pop(pilha, &topo);
        if (lista->data != topo){
            liberar_pilha(pilha);
            return 0;
        }

        lista = lista ->next;
    }
    liberar_pilha(pilha);
    return 1;
}