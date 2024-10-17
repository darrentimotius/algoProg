#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N, X;
        scanf("%d %d", &N, &X);

        // for (int j = 0; j < 1;) {
        //     if (X == 1 || X == N || ((N % 2 != 0) && (X + 1 == N))) break;
        //     if ((N / 2) >= X) {
        //         X = X - 2;
        //         count++;
        //         if (X <= 0) break;
        //     } else {
        //         N = N - 2;
        //         count++;
        //         if (N <= X) break;
        //     }
        // }

        int fromFront = X / 2;
        int fromBack;
        if (N % 2 == 0) fromBack = ((N - X + 1) / 2);
        else fromBack = ((N - X) / 2);

        printf("Case #%d: ", i);
        if (fromFront < fromBack) printf("%d\n", fromFront);
        else printf("%d\n", fromBack);
    }
    return 0;
}