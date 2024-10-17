#include <stdio.h>

int X, Y;

int fibo(int N) {
    if (N == 0) return X;
    else if (N == 1) return Y;
    else return fibo(N - 1) - fibo(N - 2);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d %d %d", &N, &X, &Y);
        printf("Case #%d: ", tc);
        printf("%d\n", fibo(N));

    }
    return 0;
}