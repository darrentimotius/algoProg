#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);
        getchar();

        int arr[N+5];
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        int flag[1000005] = {0};
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (flag[arr[i]] == 0) {
                count++;
                flag[arr[i]] = 1;
            }
        }
        printf("Case #%d: %d\n", tc, count);
    }
    return 0;
}