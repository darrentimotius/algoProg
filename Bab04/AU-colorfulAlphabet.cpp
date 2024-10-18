#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        int count = 'a';
        printf("Case #%d: ", i);
        for (int j = 0; j < N; j++) {
            printf("%c", count);
            count++;
        }
        printf("\n");
    }
    return 0;
}