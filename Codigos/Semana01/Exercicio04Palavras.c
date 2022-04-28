#include <stdio.h>

/* 
Melissa Junqueira de Barros Lins, 11201920583
*/

void imprimir_qtd_palavras(char texto[]) {
    int contador = 0;
    int quantidade_de_palavras = 0;
    int nova_palavra = 0;
    while(texto[contador] != '\0'){
        if (nova_palavra == 0){
            if (texto[contador] != '.' && texto[contador] != ' '){
                quantidade_de_palavras++;
                nova_palavra = 1;
            }
        } 
        
        if (texto[contador] == '.'){
                printf("%d\n", quantidade_de_palavras);
                quantidade_de_palavras = 0;
                nova_palavra = 0;
        } else if (texto[contador] == ' '){
            nova_palavra = 0;
        }
        contador++;
    }
    return;
}

int main(){
    char texto[5000] = "Algoritmos   e   Estruturas de Dados I. Nessa disciplina,     serao vistas estruturas de dados como   listas, pilhas, filas e arvores  .   Tambem serao vistos algoritmos de  busca  e  ordenacao.\n";
    imprimir_qtd_palavras(texto);

    return 0;

}

