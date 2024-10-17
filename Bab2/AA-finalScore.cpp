#include <stdio.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("%.2lf\n", a*20/100 + b*30/100 + c*50/100);
    return 0;
}