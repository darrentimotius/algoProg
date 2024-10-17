#include <stdio.h>

int total = 0;

void func(int A) {
    total += A;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);

        int A = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &A);
            func(A);
        }
        printf("Case #%d: %d\n", tc, total);
        total = 0;
    }
    return 0;
}