#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            if (j == 0 || j == (N - 1) || k == 0 || k == (N - 1) || j == k || j == N - 1 - k)
            printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}