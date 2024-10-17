#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N, A, B, C, D, sum = 0;
        scanf("%d %d %d %d %d", &N, &A, &B, &C, &D);

        for (int j = 1; j <= N; j++) {
            if (j % A == 0 && j % B == 0 && j % C == 0 && j % D == 0) sum ++;
            else if (j % A == 0) sum ++;
            else if (j % B == 0) sum ++;
            else if (j % C == 0) sum ++;
            else if (j % D == 0) sum ++;
        }
        printf("Case #%d: %d\n", i, sum);
    }
    return 0;
}