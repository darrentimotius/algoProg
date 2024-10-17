#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        char S[1005];
        scanf("%s", S);
        
        int l = strlen(S);

        int N;
        scanf("%d", &N);
        getchar();

        for (int i = 0; i < N; i++) {
            char temp1, temp2;
            scanf("%c %c", &temp1, &temp2);
            getchar();
            for (int j = 0; j < l; j++) {
                if (S[j] == temp1) S[j] = temp2;
            }
        }

        printf("Case #%d: %s\n", tc, S);
    }
    return 0;
}