#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        double P, N;
        scanf("%lf %lf", &P, &N);
        double jawaban = N * P / 100;
        printf("%.2lf\n", jawaban);
    }
    return 0;
}