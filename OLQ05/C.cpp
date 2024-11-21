#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        char S[1005];
        scanf("%s", S);

        int length = strlen(S);
        int flag = 1;

        for (int j = 0, k = length-1; j <= k; j++, k--) {
            if (S[j] != S[k]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) printf("Case #%d: yes\n", i);
        else printf("Case #%d: no\n", i);
    }
    return 0;
}