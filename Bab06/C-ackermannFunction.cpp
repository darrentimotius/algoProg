#include <stdio.h>

int func(int A, int B) {
    if (A == 0) return B + 1;
    else if (A > 0 && B == 0) return func(A - 1, 1);
    else if (A > 0 && B > 0) return func(A - 1, func(A, B - 1));
    else return func(A, B);
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    printf("result: %d\n", func(M, N));
    return 0;
}