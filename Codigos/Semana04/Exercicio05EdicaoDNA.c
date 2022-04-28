#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

LinkedNode *editar_dna(LinkedNode *dna_original, LinkedNode *seq_edicao) {
    LinkedNode *inicio = seq_edicao;
    while(inicio != NULL){
        if (inicio->data == 'A'){
            inicio->data = 'T';
        } else if (inicio->data == 'T'){
            inicio->data = 'A';
        } else if (inicio->data == 'G'){
            inicio->data = 'C';
        } else if (inicio->data == 'C'){
            inicio->data = 'G';
        }
        inicio = inicio->next;
    }

    int tamanho_seq_edicao = 0;
    inicio = seq_edicao;
    while(inicio != NULL){
        tamanho_seq_edicao++;
        inicio = inicio->next;
    }

    LinkedNode *inicio_dna = dna_original;
    LinkedNode *anterior_dna = NULL;
    inicio = seq_edicao;
    while(inicio_dna != NULL){
        int conta_correspondencia = 0;
        if (inicio_dna->data == inicio->data){
            while (inicio_dna->data == inicio->data)
            {
                conta_correspondencia++;
                inicio_dna = inicio_dna->next;
                inicio = inicio->next;
            }
            if (conta_correspondencia == tamanho_seq_edicao){
                for (int i = 0; i < conta_correspondencia; i++){
                    anterior_dna = inicio_dna->next;
                    inicio_dna->next = NULL;
                    inicio_dna = anterior_dna;                    
                }
            }
            conta_correspondencia = 0;
            
        }
        anterior_dna = inicio_dna;
        inicio_dna = inicio_dna->next;
    }
}

int main(){
    LinkedNode dna1;
    //dna1.data = malloc(sizeof(char));
    dna1.next = malloc(sizeof(LinkedNode));
    dna1.data = 'A';

    LinkedNode dna2;
    //dna2.data = malloc(sizeof(char));
    dna2.next = malloc(sizeof(LinkedNode));
    dna2.data = 'A';
    dna1.next = &dna2;

    LinkedNode dna3;
    //dna3.data = malloc(sizeof(char));
    dna3.next = malloc(sizeof(LinkedNode));
    dna3.data = 'C';
    dna2.next = &dna3;

    LinkedNode dna4;
    //dna4.data = malloc(sizeof(char));
    dna4.next = malloc(sizeof(LinkedNode));
    dna4.data = 'G';
    dna3.next = &dna4;

    LinkedNode dna5;
    //dna5.data = malloc(sizeof(char));
    dna5.next = malloc(sizeof(LinkedNode));
    dna5.data = 'T';
    dna4.next = &dna5;

    LinkedNode dna6;
    //dna6.data = malloc(sizeof(char));
    dna6.next = malloc(sizeof(LinkedNode));
    dna6.data = 'C';
    dna5.next = &dna6;
    dna6.next = NULL;

    LinkedNode seq1;
    //seq1.data = malloc(sizeof(char));
    seq1.next = malloc(sizeof(LinkedNode));
    seq1.data = 'G';

    LinkedNode seq2;
    //seq2.data = malloc(sizeof(char));
    seq2.next = malloc(sizeof(LinkedNode));
    seq2.data = 'C';
    seq1.next = &seq2;

    LinkedNode seq3;
    //seq3.data = malloc(sizeof(char));
    seq3.next = malloc(sizeof(LinkedNode));
    seq3.data = 'A';
    seq2.next = &seq3;
    seq3.next = NULL;

    LinkedNode *inicioDNA = &dna1;
    while(inicioDNA != NULL){
        printf("%s -> ", inicioDNA->data);
        inicioDNA = inicioDNA->next;
    } 
    
    LinkedNode *inicioseq = &seq1;
    while(inicioseq != NULL){
        printf("%s -> ", inicioseq->data);
        inicioseq = inicioseq->next;
    }    

    return 0;
}