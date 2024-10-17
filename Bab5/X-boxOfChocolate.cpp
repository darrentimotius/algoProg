#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N, M;
        scanf("%d %d", &N, &M);

        int matrix[N+5][M+5];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        long long int sum = 0;
        for (int i = 0; i < N; i++) {
            long long int temp = 0;
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] > temp) temp = matrix[i][j];
            }
            sum += temp;
        }
        printf("Case #%d: %lld\n", tc, sum);
    }
    return 0;
}