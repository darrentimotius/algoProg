#include <stdio.h>

int fibo(int N) {
    if (N == 0) return 0;
    else if (N == 1) return 1;
    else if (N == 2) return 1;
    return fibo(N - 1) + fibo(N - 3);
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", fibo(N));
    return 0;
}