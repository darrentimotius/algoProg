#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);
        int A[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        int count = 0;
        for (int i = 0; i < N; i++) {
            int found = 0;
            for (int j = 0; j < N; j++) {
                    for (int k = 0; k < N; k++) {
                        if (k != j && A[i] == A[j] + A[k]) {
                            found = 1;
                            break;
                        }
                    }
            if (found == 1) break;
            }
            if (found == 1) count++;
        }
        printf("Case #%d: %d\n", tc, count);
    }
    return 0;
}