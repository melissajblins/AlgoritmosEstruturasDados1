#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore NoArvore;
struct NoArvore {
    int chave;
    int altura;
    NoArvore *esq, *dir;
};

typedef struct LinkedNode LinkedNode;
struct LinkedNode {
   int data;
   LinkedNode *next;
};

typedef struct PilhaDinamica PilhaDinamica;
struct PilhaDinamica{
    LinkedNode *topo;
};

int altura_arvore(NoArvore *raiz){
    if (raiz == NULL){
        return -1;
    } else {
        return raiz->altura;
    }
}

int calcula_fator_balanceamento(NoArvore *raiz){
    return(altura_arvore(raiz->esq) - altura_arvore(raiz->dir));
}

int maior(int valor1, int valor2){
    return (valor1 > valor2 ? valor1 : valor2);
}

NoArvore *inserir_arvore(NoArvore *raiz, int valor) {
    if (raiz == NULL){
        NoArvore *novo_no = malloc(sizeof(NoArvore));
        novo_no->chave = valor;
        novo_no->altura = 0;
        novo_no->esq = NULL;
        novo_no->dir = NULL;
        return novo_no;
    }
    if(valor < raiz->chave){
        raiz->esq = inserir_arvore(raiz->esq, valor);
    } else if (valor > raiz->chave){
        raiz->dir = inserir_arvore(raiz->dir, valor);
    } else if (valor == raiz->chave){
        return raiz; 
    }

    raiz->altura = 1 +maior(altura_arvore(raiz->esq), altura_arvore(raiz->dir));
    return raiz;

}

PilhaDinamica *criar_pilha(){
    PilhaDinamica *pilha = malloc(sizeof(PilhaDinamica));
    pilha->topo = NULL;
    return pilha;
}

int push(PilhaDinamica *pilha, int item){
    LinkedNode *novo_item = malloc(sizeof(LinkedNode));
    if(novo_item == NULL){
        return 0;
    }

    novo_item->data = item;
    novo_item->next = pilha->topo;
    pilha->topo = novo_item;

    return 1;
}

int pop(PilhaDinamica *pilha){
    if (pilha->topo == NULL){
        return 0;
    }

    LinkedNode *no = pilha->topo;
    pilha->topo = pilha->topo->next;

    printf("[No desbalanceado: %d]\n", no->data);

    free(no);
    return 1;
}

void liberar_lista(LinkedNode *no){
    if (no == NULL){
        return;
    }
    liberar_lista(no->next);
    free(no);
}

void liberar_pilha(PilhaDinamica *pilha){
    liberar_lista(pilha->topo);
    free(pilha);
}

void percurso_em_ordem(NoArvore *raiz, int valor, int *flag){
    if (raiz == NULL){
        return;
    }

    PilhaDinamica *pilha = criar_pilha();

    while (raiz->chave != valor){
        if(raiz->chave > valor){
            if((calcula_fator_balanceamento(raiz) < -1) || (calcula_fator_balanceamento(raiz) > 1)){
                push(pilha, raiz->chave);
                *flag = *flag + 1;
            }
            raiz = raiz->esq;
        } else if(raiz->chave < valor) {
            if((calcula_fator_balanceamento(raiz) < -1) || (calcula_fator_balanceamento(raiz) > 1)){
                push(pilha, raiz->chave);
                *flag = *flag + 1;
            }
            raiz = raiz->dir;
        } else {
           if((calcula_fator_balanceamento(raiz) < -1) || (calcula_fator_balanceamento(raiz) > 1)){
                push(pilha, raiz->chave);
                *flag = *flag + 1;
            }
            return; 
        }
    }

    int resultado = 1;
    while(resultado == 1){
        resultado = pop(pilha);
    }

    liberar_pilha(pilha);
}

void percurso_pos_ordem(NoArvore *raiz){
    if (raiz == NULL){
        return;
    }

    percurso_pos_ordem(raiz->esq);
    percurso_pos_ordem(raiz->dir);
    printf("%d ", raiz->chave);
}

void libera(NoArvore *raiz){
    if (raiz == NULL){
        return;
    }
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}

NoArvore *inserir(NoArvore *raiz, int valor) {
    printf("Inserir:%d\n", valor);

    NoArvore *no;

    no = inserir_arvore(raiz, valor);

    int flag = 0;

    if (raiz == NULL) {
        printf("[Ja esta balanceada]\n");
    } else{
        percurso_em_ordem(raiz, valor, &flag);
    }

    if (flag == 0 && raiz != NULL){
        printf("[Ja esta balanceada]\n");
    }

    if(raiz == NULL){
        return no;
    } else {
        return raiz;
    }
}

int altura(NoArvore *n) {
    return altura_arvore(n);
}

void liberar_arvore(NoArvore *raiz) {
    percurso_pos_ordem(raiz);

    libera(raiz);

    return;

}

int main() {
	NoArvore *raiz = NULL;
	char operacao;
	do {
		scanf(" %c", &operacao);
		switch (operacao) {
			case 'I' : {
				int valor;
				scanf("%d", &valor);
				raiz = inserir(raiz, valor);
				break;
			}
			case 'A' : {
				printf("A=%d\n", altura(raiz));
				break;
			}
			case 'P' : {
				printf("[");
				liberar_arvore(raiz);
				printf("]\n");
				break;
			}
		}
	} while (operacao != 'P');
    
	return 0;
}