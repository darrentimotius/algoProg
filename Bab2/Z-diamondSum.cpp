#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        double a, b, c, d;
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        double jawaban = 2*a + 2*b + 4*c/3 + d/2;
        printf("%.2lf\n", jawaban);
    }
    return 0;
}