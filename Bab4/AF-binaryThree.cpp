#include <stdio.h>

// Function to count the number of ON bits in a number
int countOnBits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);

        int A[N];
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[j]);
        }

        int atLeast3OnBits = 0;
        int lessThan3OnBits = 0;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int xorResult = A[i] ^ A[j];
                int onBits = countOnBits(xorResult);
                if (onBits >= 3) {
                    atLeast3OnBits++;
                } else {
                    lessThan3OnBits++;
                }
            }
        }

        printf("Case #%d: %d %d\n", t, atLeast3OnBits, lessThan3OnBits);
    }

    return 0;
}