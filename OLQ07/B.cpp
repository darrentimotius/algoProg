#include <stdio.h>

int jojo(int N, int X, int Y) {
    if (N == 0) return X;
    else if (N == 1) return Y;
    return jojo(N - 1, X, Y) - jojo(N - 2, X, Y);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N, X, Y;
        scanf("%d %d %d", &N, &X, &Y);
        printf("Case #%d: %d\n", tc, jojo(N, X, Y));
    }
    return 0;
}