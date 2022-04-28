#include <stdio.h>

void muda_valor_a(double param) {
    param = 99;
    printf("A=%lf\n", param); // 99
}

void muda_valor_b(double *param) {
    *param = 99;
    printf("B=%lf\n", *param); // 99
}

int main() {
    double n = 507;
    printf("%lf\n", n); // 507
    muda_valor_a(n); 
    printf("%lf\n", n); // 507
    muda_valor_b(&n); // Note a chamada da função
    printf("%lf\n", n); // 99
    return 0;
}