#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   char *data; 
   LinkedNode *next;
};

int compara_data(char *Str1, char *Str2, int *comparacoes){
    *comparacoes = *comparacoes + 1;
    int resultado = 0;
    while (*Str1 != '\0' || *Str2 != '\0'){
        if (*Str1 == *Str2){
            Str1++;
            Str2++;
        }
        else if ((*Str1 == '\0' && *Str2 != '\0') || (*Str1  != '\0' && *Str2 == '\0') || *Str1 != *Str2){
            if(*Str1 == '\0'){
                return -1;
            } else if(*Str2 == '\0'){
                return 1;
            }
            return (int)(*Str1-*Str2);
        }
    }
}

LinkedNode *acha_meio(LinkedNode *inicio){
    LinkedNode *meio = inicio;
    LinkedNode *final = inicio->next;

    while(meio->next != NULL && (final != NULL && final->next != NULL)){
        meio = meio->next;
        final = final->next->next;
    }

    return meio;
    
}

LinkedNode *merge_sort(LinkedNode *a, LinkedNode *b, int *comparacoes){
    LinkedNode *novo_inicio = NULL;
    LinkedNode *final = NULL;

    if(compara_data(b->data, a->data, comparacoes) >= 0){
        novo_inicio = a;
        a = a->next;
    } else {
        novo_inicio = b;
        b = b->next;
    }

    final = novo_inicio;

    while(a != NULL && b != NULL){
        if(compara_data(b->data, a->data, comparacoes) >= 0){
            final->next = a;
            a = a->next;
        } else {
            final->next = b;
            b = b->next;
        }
        final = final->next;
    }

    if (a != NULL){
        final->next = a;
    }
    if(b != NULL){
        final->next = b;
    }

    return novo_inicio; 
}

LinkedNode *merge_sort_auxiliar(LinkedNode *inicio, int *comparacoes){
    if (inicio == NULL || inicio->next == NULL){
        return inicio;
    }

    LinkedNode *meio, *no_auxiliar, *novo_inicio;

    meio = acha_meio(inicio);

    no_auxiliar = meio->next;
    meio->next = NULL;

    novo_inicio = merge_sort(merge_sort_auxiliar(inicio, comparacoes), merge_sort_auxiliar(no_auxiliar, comparacoes), comparacoes);
}

LinkedNode *mergesort(LinkedNode *inicio, int *comparacoes) {
    *comparacoes = 0;
    
    inicio = merge_sort_auxiliar(inicio, comparacoes);

    return inicio;
}