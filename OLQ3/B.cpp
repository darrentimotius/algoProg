#include <stdio.h>

int main() {
    long long int N;
    scanf("%lld", &N);

    long long int ans = 1;
    for (int i = 0; i < N; i++) {
        ans *= 2;
    }
    printf("%lld\n", ans - 1);

    // printf("%lld\n", (1llu << N) - 1);
    return 0;
}