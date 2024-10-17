#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N, M, Q;
        /*
        N = banyak temen
        M = banyak ruangannya
        Q = temen yang bakal masuk
        */
        scanf("%d %d %d", &N, &M, &Q);

        int whichRoom[N+5][M+5];
        // baris = temen ke brapa
        // kolom = ruangan mana yang pengen didatengin
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &whichRoom[i][j]);
            }
        }

        int willVisit[Q+5];
        // temen yang mana yang mau masuk
        for (int i = 0; i < Q; i++) {
            scanf("%d", &willVisit[i]);
        }

        int roomLamp[M+5] = {0};
        for (int i = 0; i < Q; i++) {
            for (int k = 0; k < M; k++) {
                roomLamp[k] += whichRoom[willVisit[i] - 1][k];
            }
        }

        printf("Case #%d:\n", tc);
        for (int i = 0; i < M; i++) {
            if (roomLamp[i] % 2 == 1) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}