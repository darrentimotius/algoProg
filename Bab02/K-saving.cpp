#include <stdio.h>

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);

    for (int i = 1; i <= 3; i++) {
        a += a * b / 100;
    }
    printf("%.2lf\n", a);
    return 0;
}