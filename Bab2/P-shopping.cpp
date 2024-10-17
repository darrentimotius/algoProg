#include <stdio.h>

int main() {
    // N = Diskon
    // P = Harga setelah diskon
    double N, P;
    scanf("%lf %lf", &N, &P);
    double sum = P * 100 / (100 - N);
    printf("$%.2lf\n", sum);

    scanf("%lf %lf", &N, &P);
    double sum1 = P * 100 / (100 - N);
    printf("$%.2lf\n", sum1);

    scanf("%lf %lf", &N, &P);
    double sum2 = P * 100 / (100 - N);
    printf("$%.2lf\n", sum2);

    scanf("%lf %lf", &N, &P);
    double sum3 = P * 100 / (100 - N);
    printf("$%.2lf\n", sum3);
    
    return 0;
}