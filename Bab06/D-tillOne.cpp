#include <stdio.h>

int func(int A) {
    if (A == 1) return 1;
    else if (A % 2 == 0) return func(A / 2);
    else if (A % 2 == 1) return func(A - 1) + func(A + 1);
    else return A;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);
        printf("Case #%d: ", tc);
        printf("%d\n", func(N));
    }
    return 0;
}