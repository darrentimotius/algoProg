#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        char ans[N+5];
        scanf("%s", ans);

        char key[N+5];
        scanf("%s", key);

        int count = 0;
        for (int j = 0; j < N; j++) {
            if (ans[j] == key[j]) count++;
        }

        printf("Case #%d: %d\n", i, count * 100 / N);
    }
    return 0;
}