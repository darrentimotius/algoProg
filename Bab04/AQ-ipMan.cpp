#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        char S[105];
        scanf("%s", S);

        int length = strlen(S);
        int flag = 0;
        int prevNumber = 0;
        int countDot = 0;
        for (int j = 0; j < length; j++) {
            if (S[j] != '.') {
                prevNumber = 1;
            } else {
                if (prevNumber != 1) {
                    flag = 0;
                    break;
                } else {
                    countDot++;
                    prevNumber = 0;
                }
            }
        }

        printf("Case #%d: ", i);
        if (countDot == 5) printf("YES\n");
        else printf("NO\n");
    }
}