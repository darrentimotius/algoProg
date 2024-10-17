#include <stdio.h>

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%.2lf%%\n", (a - b)/a * 100);
    return 0;
}