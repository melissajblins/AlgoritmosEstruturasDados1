#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr_numero = malloc(sizeof(int));
    scanf("%d", ptr_numero);
    printf("%d\n", *ptr_numero);
    
    return 0;
}