#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);

        int score[N+5];
        for (int i = 0; i < N; i++) {
            scanf("%d", &score[i]);
        }

        int bibi, lili;
        scanf("%d %d", &bibi, &lili);

        printf("Case #%d : ", tc);
        if (score[bibi - 1] > score[lili - 1]) printf("Bibi\n");
        else if (score[bibi - 1] < score[lili - 1]) printf("Lili\n");
        else printf("Draw\n");
        
        
    }
    return 0;
}