#include <stdio.h>
#include <stdlib.h>

void frequencia_string(char *str, char *texto, int *qtd){
    *qtd = 0;
    int tamanho_texto = 0;
    int tamanho_string = 0;

    while(str[tamanho_string] != '\0'){
        tamanho_string++;
    }

    while(texto[tamanho_texto] != '\0'){
        if (texto[tamanho_texto] == str[0] || texto[tamanho_texto] == (str[0] + 32) || texto[tamanho_texto] == (str[0] - 32)){
            int posicao_inicial = tamanho_texto;
            int varre_string = 0;
            int corresponde = 1;
            for (tamanho_texto; tamanho_texto < posicao_inicial + tamanho_string; tamanho_texto++){
                if (texto[tamanho_texto] == str[varre_string] || texto[tamanho_texto] == (str[varre_string] + 32) || texto[tamanho_texto] == (str[varre_string] - 32)){
                    varre_string++;
                } else{
                    corresponde = 0;
                    break;
                }
            }
            if (corresponde){
                *qtd = *qtd + 1;
                tamanho_texto = tamanho_texto - 2;
            } else {
                tamanho_texto = posicao_inicial;
            }
        }
        tamanho_texto++;
    }
}

int main(){
    char str[50] = "ABC";
    char texto[5000] = "abcdeABCaBcAbcAbCABcabCaBCde\n";
    int qtd = 0;
    frequencia_string(str, texto, &qtd);

    return 0;
}