#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N, M;
        scanf("%d %d", &N, &M);

        int total[505];
        for (int j = 0; j < N; j++) {
            int temp = 0;
            for (int k = 0; k < M; k++) {
                int A;
                scanf("%d", &A);
                if (k == 0) temp = A;
                if (A > temp) temp = A;
            }
            total[j] = temp;
        }
        
        long long int ans = 0;
        for (int j = 0; j < N; j++) {
            ans += total[j];
        }

        printf("Case #%d: %lld\n", i, ans);
    }
    return 0;
}