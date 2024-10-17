#include <stdio.h>

int main() {
    int A;
    scanf("%d", &A);
    int N = A / 2;
    printf("%d = %d + %d\n", A, N, A - N);
    return 0;
}