#include <stdio.h>

int main() {
    double a, b, c, d;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    printf("%.2lf\n", (2*a) + (2*b) + (2*c) + d);

    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    printf("%.2lf\n", (2*a) + (2*b) + (2*c) + d);

    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    printf("%.2lf\n", (2*a) + (2*b) + (2*c) + d);
    return 0;
}