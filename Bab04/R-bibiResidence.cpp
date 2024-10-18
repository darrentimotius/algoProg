#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        int temp1 = 0, temp2 = -1;
        int A;

        scanf("%d", &temp1);
        for (int j = 1; j < N; j++) {
            scanf("%d", &A);

            int diff = A - temp1;

            if (diff < 0) {
                diff = -diff;
            }

            if (temp2 == -1 || diff < temp2) {
                temp2 = diff;
            }

            temp1 = A;
        }
        printf("Case #%d: %d\n", i, temp2);
    }
}