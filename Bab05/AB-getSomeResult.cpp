#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        int mat1[N+5][N+5];
        int mat2[N+5][N+5];
        int mat3[N+5][N+5];

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                scanf("%d", &mat1[j][k]);
            }
        }

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                scanf("%d", &mat2[j][k]);
            }
        }

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                scanf("%d", &mat3[j][k]);
            }
        }

        int result1[N+5][N+5];
        for (int a = 0; a < N; a++) {
            for (int b = 0; b < N; b++) {
                result1[a][b] = 0;
                for (int c = 0; c < N; c++) {
                    result1[a][b] += mat1[a][c] * mat2[c][b];
                }
            }
        }

        int result2[N+5][N+5];
        for (int a = 0; a < N; a++) {
            for (int b = 0; b < N; b++) {
                result2[a][b] = 0;
                for (int c = 0; c < N; c++) {
                    result2[a][b] += result1[a][c] * mat3[c][b];
                }
            }
        }

        printf("Case #%d:\n", i);
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                printf("%d", result2[j][k]);
                if (k != N - 1) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}