#include <stdio.h>

int main() {
    int T, X;
    scanf("%d", &T);
    getchar();

    for (int i = 0; i < T; i++) {
        scanf("%d", &X);
        getchar();

        long long int matrix[101][101], array[101];

        for (int j = 0; j < X; j++) {
            for (int k = 0; k < X; k++) {
                scanf("%lld", &matrix[j][k]);
            }
        }

        printf("Case #%d: ", i + 1);

        for (int j = 0; j < X; j++) {
            int sum = 0;

            for (int k = 0; k < X; k++) {
                sum += matrix[k][j];
            }
            array[j] = sum;
            printf("%lld", array[j]);
            if (j < X - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}