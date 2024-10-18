#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        char S[1005];
        scanf("%s", S);

        int jawaban[1005];
        int length = strlen(S);
        for (int j = 0; j < length; j++) {
            jawaban[j] = S[j];
        }

        printf("Case %d: ", i);
        for (int j = 0; j < length; j++) {
            printf("%d", jawaban[j]);
            if (j != length - 1) printf("-");
        }
        printf("\n");
    }
    return 0;
}