#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        if (N % 2 == 0) return 0;
        else {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    if (j == 0 || j == (N - 1) || k == 0 || k == (N - 1) || j == k || j == N - 1 - k)
                    printf("*");
                    else printf(" ");
                }
                printf("\n");
            }
        }
        printf("\n");
    }
}