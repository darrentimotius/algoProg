#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N, M, sum = 0;
        scanf("%d %d", &N, &M);

        for (int j = 1; j <= N; j++) {
            int harga;
            scanf("%d", &harga);
            sum += harga;
        }

        if (sum <= M) printf("Case #%d: No worries\n", i);
        else printf("Case #%d: Wash dishes\n", i);
    }
    return 0;
}