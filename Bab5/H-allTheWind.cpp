#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        int matrix[N + 5][N + 5];
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                scanf("%d", &matrix[j][k]);
            }
        }

        long long int ans[N+5];
        printf("Case #%d: ", i);
        for (int j = 0; j < N; j++) {
            long long int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += matrix[k][j];
            }
            ans[j] = sum;
            if (j != 0) printf(" ");
            printf("%lld", ans[j]);
        }
        printf("\n");
    }
    return 0;
}