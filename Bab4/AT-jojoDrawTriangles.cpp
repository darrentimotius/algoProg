#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N - j - 1; k++) {
                printf(" ");
            }
            for (int k = 0; k < 2 * j + 1; k++) {
                printf("*");
            }
            printf("\n");
        }
    }
}