#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);
        int att[N+5];
        int min[N+5];

        for (int j = 0; j < N; j++) {
            scanf("%d", &att[j]);
        }

        for (int j = 0; j < N; j++) {
            scanf("%d", &min[j]);
        }

        int count = 0;
        for (int j = 0; j < N; j++) {
            if (att[j] < min[j]) count++;
        }
        printf("Case #%d: %d\n", i, count);
    }
    return 0;
}