#include <stdio.h>

int main() {
    int T;
    long long A;
    long long B;

    scanf("%d", &T);
    for (int i = 0; i < 3; i++) {
        scanf("%lld %lld", &A, &B);
        printf("%.2lf\n", 1.0*A*B/360);
    }
    return 0;
}