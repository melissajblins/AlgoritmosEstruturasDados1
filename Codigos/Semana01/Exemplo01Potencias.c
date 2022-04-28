#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int qtd_potencias = 0;
	int i;
	for (i = 0; i < n; i++){
		int novo_numero;
		scanf("%d", &novo_numero);

        int eh_potencia2 = 1;
        if (novo_numero < 1) eh_potencia2 = 0;
    	while (novo_numero > 1) {
    		if (novo_numero % 2 != 0) {
    		    eh_potencia2 = 0;
    			break;
    		}
    		novo_numero = novo_numero / 2;
    	}
		if (eh_potencia2) qtd_potencias++;
	}	

	printf("%d\n", qtd_potencias);
}