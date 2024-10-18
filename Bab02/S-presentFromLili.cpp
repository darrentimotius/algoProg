#include <stdio.h>

int main() {
    double L, B, H;
    scanf("%lf %lf %lf", &L, &B, &H);
    double area = B * H + B * L * 3;
    printf("%.3lf\n", area);
    return 0;
}