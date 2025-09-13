#include <stdio.h>

int main() {
    double X, Y;
    scanf("%lf %lf", &X, &Y);

    printf("%.2lf%%\n", X / Y * 100);
    return 0;
}