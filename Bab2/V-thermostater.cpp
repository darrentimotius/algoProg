#include <stdio.h>

int main() {
    int T, A;

    scanf("%d", &T);
    for (int i = 0; i < 3; i++) {
    scanf("%d", &A);
    double R = 4.0/5*A;
    double F = 9.0/5*A + 32;
    double K = A + 273;
    printf("%.2lf %.2lf %.2lf\n", R, F, K);
    }
    return 0;
}