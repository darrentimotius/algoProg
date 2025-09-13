#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);
        
        printf("Case #%d:\n", i);
        for (int j = 1; j <= N; j++) {
            if (j % 15 == 0) printf("%d Lili\n", j);
            else if (j % 5 == 0) printf("%d Jojo\n", j);
            else if (j % 3 == 0) printf("%d Jojo\n", j);
            else printf("%d Lili\n", j);
        }
    }
    return 0;
}