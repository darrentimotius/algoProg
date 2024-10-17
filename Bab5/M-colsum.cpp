#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        int matrix[N+5][N+5];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        printf("Case #%d: ", i);
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += matrix[k][j];
            }
            printf("%d", sum);
            if (j < N - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}