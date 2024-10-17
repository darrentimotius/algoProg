#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N, K;
        scanf("%d %d", &N, &K);
        getchar();

        char plot[N+5];
        scanf("%s", plot);
        getchar();

        int stairCase = 0, firstStair = -1, lastStair = -1;
        for (int i = 0; i < N; i++) {
            if (plot[i] == '1') {
                firstStair = i + 1;
                break;
            }
        }

        for (int i = N - 1; i >= 0; i--) {
            if (plot[i] == '1') {
                lastStair = i;
                break;
            }
        }

        for (int i = 0; i < N; i++) {
            if (plot[i] == '1') {
                stairCase++;
            }
        }
        
        int flag = 0;
        if (K >= N) {
            flag = 1;
        } else if (firstStair == -1) {
            flag = 0;
        } else if ((firstStair <= K) && (N - lastStair <= K) && (stairCase != 1)) {
            flag = 1;
        }

        printf("Case #%d: ", tc);
        if (flag == 1) printf("Alive\n");
        else printf("Dead\n");

    }
    return 0;
}