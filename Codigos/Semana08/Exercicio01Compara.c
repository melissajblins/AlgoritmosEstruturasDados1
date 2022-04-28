typedef struct ItemVetor ItemVetor;
struct ItemVetor {
    char *modelo;
    char *planeta;
    int autonomia;
};

int compara_autonomia(int autonomia1, int autonomia2){
    if(autonomia1 < autonomia2){
        return -1;
    } else if (autonomia1 > autonomia2 ){
        return 1;
    } else {
        return 0;
    }
}

int codigo(char *Str1, char *Str2){
    if(*Str1 == '\0'){
        return (int)(*Str2);
    }
    else if(*Str2 == '\0'){
        return (int)(*Str1);
    }
    return (int)(*Str1-*Str2);
}

int compara_modelo_planeta(char *Str1, char *Str2){
    int resultado = 0;
    while (*Str1 != '\0' || *Str2 != '\0'){
        if (*Str1 == *Str2){
            Str1++;
            Str2++;
        }
        else if ((*Str1 == '\0' && *Str2 != '\0') || (*Str1  != '\0' && *Str2 == '\0') || *Str1 != *Str2){
            resultado = codigo(Str1,Str2);
            break;
        }
    }
    return resultado;
}

int comparar(ItemVetor item1, ItemVetor item2) {
    int resultado;
    resultado = compara_autonomia(item1.autonomia, item2.autonomia);
    if (resultado == 0){
        resultado = compara_modelo_planeta(item1.planeta, item2.planeta);
        if (resultado == 0){
            resultado = compara_modelo_planeta(item1.modelo, item2.modelo);
        }
    }
    return resultado;    
}