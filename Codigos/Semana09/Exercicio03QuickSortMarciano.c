int peso(int numero){
    switch (numero){
        case 0:
            return 1;
            break;
        case 5:
            return 2;
            break;
        case 6:
            return 3;
            break;
        case 4:
            return 4;
            break;
        case 8:
            return 5;
            break;
        case 9:
            return 6;
            break;
        case 7:
            return 7;
            break;
        case 3:
            return 8;
            break;
        case 1:
            return 9;
            break;
        case 2:
            return 10;
            break;
    }
}

int calcula_numero(int valor){
    int novo_numero = 0;
    int volta = 1;
    while(valor > 0){
        novo_numero += peso(valor % 10) * volta;
        valor = valor / 10;
        volta = volta * 10;
    }
    return novo_numero;
}

int compara(int valor1, int valor2, int *comparacoes){
    *comparacoes = *comparacoes + 1;

    valor1 = calcula_numero(valor1);
    valor2 = calcula_numero(valor2);

    return(valor1 > valor2);
}

int particiona(int *v, int esq, int dir, int *comparacoes) {
    int pivo = v[dir];
    int i, ultimo_menores = esq-1;
    for (i = esq; i < dir; i++)
        if (compara(pivo, v[i], comparacoes)) {
            ultimo_menores++;
            int tmp = v[i];
            v[i] = v[ultimo_menores];
            v[ultimo_menores] = tmp;
        }
    v[dir] = v[ultimo_menores+1];
    v[ultimo_menores+1] = pivo;
    return ultimo_menores+1;
}

void quick_sort(int *v, int esq, int dir, int *comparacoes) {
    if (esq < dir) {
        int indice_pivo = particiona(v, esq, dir, comparacoes);
        quick_sort(v, esq, indice_pivo - 1, comparacoes);
        quick_sort(v, indice_pivo + 1, dir, comparacoes);
    }
}

int quicksortm(int *v, int n) {
    int comparacoes = 0;

    quick_sort(v, 0, n - 1, &comparacoes);

    return comparacoes; 
}