#include <stdio.h>
#include <stdlib.h>

struct lifo{
    int topo;
    int pilha[100];
};
void empilha(struct lifo *pilha, int item){
    pilha->pilha[pilha->topo++] = item;
}
int empty(struct lifo *pilha){
        if(pilha->topo == 0) return -1;
        else return 0;
}
int desempilha(struct lifo *pilha){
        if(!empty(pilha)){
            return pilha->pilha[--pilha->topo];
        }
}
int top(struct lifo *pilha){
        if(!empty(pilha)){
            return pilha->pilha[pilha->topo-1];
        }
}
void main(){
    struct lifo arquivo;
    int comeco, fim, id, i;
    char expressao[100];
    i = comeco = fim = arquivo.topo = 0;
    fgets(expressao, 100, stdin);
    for(i; expressao[i] != '\0'; i++){
        if((expressao[i] == '(') || (expressao[i] == '[') || (expressao[i] == '{')){
            comeco++;
            if(expressao[i] == '('){
                id = 1;
            } else if(expressao[i] == '['){
                id = 2;
            }else{
                id = 3;
            } 
            empilha(&arquivo, id);
        }else if((expressao[i] == ')') || (expressao[i] == ']') || (expressao[i] == '}')){
            fim++;
            if(expressao[i] == ')'){
                id = 1;
            } else if(expressao[i] == ']'){
                id = 2;
            } else{
                id = 3;
            }
            if(id == top(&arquivo)){
                 desempilha(&arquivo);
            }
        }       }
    if(empty(&arquivo)){
        if(comeco == fim){
            printf("SIM");
        }else{
            printf("NAO");
        }
    }else{
        printf("NAO");
    }
    if(i - comeco - fim < comeco + fim + 1){
        printf("NAO");
    } 
}