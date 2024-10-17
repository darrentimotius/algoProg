#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N, K;
        scanf("%d %d", &N, &K);

        char S[N+5];
        scanf("%s", S);

        int length = strlen(S);
        printf("Case #%d: ", i);
        for (int j = 0; j < length; j++) {
            int temp = S[j] - 'a';
            temp += K;
            if (temp > 25) {
                temp %= 26;
                printf("%c", temp + 'a');
            } else {
                printf("%c", S[j] + K);
            }
        }
        printf("\n");
    }
    return 0;
}