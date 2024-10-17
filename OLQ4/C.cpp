#include <stdio.h>

int main() {
    long long int T;
    scanf("%lld", &T);

    for (long long int i = 1; i <= T; i++) {
        long long int N, M;
        scanf("%lld %lld", &N, &M);

        long long int player[M + 10];
        for (long long int j = 0; j < M; j++) {
            scanf("%lld", &player[j]);
        }

        long long int treasureLocation[N + 10];
        for (long long int j = 0; j <= N; j++) {
            treasureLocation[j] = 1;
        }

        long long int failedPlayer = 0;
        for (long long int j = 0; j < M; j++) {
            if (treasureLocation[player[j]] == 0) failedPlayer++;
            else treasureLocation[player[j]] = 0;
        }
        printf("Case #%lld: %lld\n", i, failedPlayer);
    }
    return 0;
}