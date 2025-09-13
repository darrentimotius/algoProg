#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);

        long long int likes[N+5];
        likes[1] = 0;
        likes[2] = 1;
        for (int i = 3; i <= N; i++) {
            likes[i] = likes[i-1] + likes[i-2];
        }
        printf("Case #%d: %lld\n", tc, likes[N]);
    }
    return 0;
}