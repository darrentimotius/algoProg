#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        long long int A, B, sum = 0;
        scanf("%lld %lld", &A, &B);
        sum = A;

        for (int j = 0; j < 1;) {
            if ((A - B) < 0) break;
            A -= B, A++, sum++;
        }
        printf("Case #%d: %lld\n", i, sum);
    }
    return 0;
}