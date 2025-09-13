#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N, K;
        scanf("%d %d", &N, &K);

        // int array[10005];
        int count = 0;
        for (int i = 0; i < N; i++) {
            int temp;
            scanf("%d", &temp);
            if (temp >= K) count++;
        }

        printf("Case #%d: %d\n", tc, count);
    }
    return 0;
}