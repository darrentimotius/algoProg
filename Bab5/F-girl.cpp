#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        char S[100005];
        scanf("%s", S);

        int l = strlen(S);
        int count = 0;
        int checking[100] = {0};
        for (int j = 0; j < l; j++) {
            if (checking[S[j] - 'a'] == 0) {
                count++;
                checking[S[j] - 'a'] = 1;
            }
        }

        if (count % 2 == 0) printf("Case #%d: Yay\n", i);
        else printf("Case #%d: Ewwww\n", i);
    }
    return 0;
}