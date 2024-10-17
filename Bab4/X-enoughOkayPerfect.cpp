#include <stdio.h>

int main() {
    int A, N = 1;
    scanf("%d", &A);
    for (int i = 1; i <= A; i++) {
        N = N * 2 + 1;
    }
    printf("%d\n", N);
    return 0;
}