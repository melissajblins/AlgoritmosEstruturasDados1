#include <stdio.h>
#include <stdlib.h>

void imprimir_vetor(int *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++){
        if(i == 0){
            printf("[%d ", vetor[i]);
        } else if (i == tamanho - 1){
            printf("%d]", vetor[i]);
        } else {
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");
}

void imprimir(char *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("%c", vetor[i]);
    }
    printf("\n");
}


int compara_string(char *Str1, char *Str2, int *comparacoes){
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

void countingsort(char *v, int n, int k) {
    int c[k + 1];
    int i;
    for (i = 0; i < k + 1; i++)
        c[i] = 0;  
    for (i = 0; i < n; i++)
        c[v[i]-65]++;
    imprimir_vetor(c, (k + 1));
    for (i = 1; i < k + 1; i++)
        c[i] += c[i - 1];
    imprimir_vetor(c, (k + 1));
    int saida[n];
    int atual;
    for (i = n - 1; i >= 0; i--) {
        saida[c[v[i] - 65] - 1] = v[i];
        c[v[i] - 65]--;
    }
    for (i = 0; i < n; i++)
        v[i] = saida[i];
}

int main() {
    
    char palavra[1000];

    scanf("%s", palavra);
    
    char copia_palavra[1000];
    
    strcpy(copia_palavra, palavra);

    int tamanho = 0;
    while(copia_palavra[tamanho] !=  '\0'){
        tamanho++;
    }

    countingsort(palavra, tamanho, 25);

    imprimir(palavra, tamanho);

    return 0;
}

void countingsort(int *v, int n, int k) {
    int c[k + 1];
    int i;
    for (i = 0; i < k + 1; i++)
        c[i] = 0;
    for (i = 0; i < n; i++)
        c[v[i]-65]++;
    for (i = 1; i < k + 1; i++)
        c[i] += c[i - 1];
    int saida[n];
    int atual;
    for (i = n - 1; i >= 0; i--) {
        atual = v[i];
        saida[c[atual] - 1] = atual;
        c[atual]--;
    }
    for (i = 0; i < n; i++)
        v[i] = saida[i];
}