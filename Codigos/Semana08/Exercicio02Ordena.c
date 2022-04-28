typedef struct ItemVetor ItemVetor;
struct ItemVetor {
    char *modelo;
    char *planeta;
    int autonomia;
};

int comparar(ItemVetor item1, ItemVetor item2);

void ordenar_vetor(ItemVetor v[], int n) {
    int i, k, trocou = 1;
    for (i = 0; i < n - 1 && trocou; i++){
        trocou = 0;
        for (k = 0; k < n - 1 - i; k++){
            if(comparar(v[k], v[k + 1]) > 0){
                ItemVetor temporario = v[k];
                v[k] = v[k + 1];
                v[k + 1] = temporario;
                trocou = 1;
            }
        }
    }
}