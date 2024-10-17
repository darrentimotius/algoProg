#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        int temp;
        int count = 1;
        scanf("%d", &temp);

        for (int j = 1; j < N; j++) {
            int A;
            scanf("%d", &A);

            if (A == temp) count++;
            if (A > temp) {
                temp = A;
                count = 1;
            }
        }
        printf("Case #%d: %d\n", i, count);
    }
}