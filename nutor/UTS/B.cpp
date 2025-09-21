#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        char H[1005], E[1005];
        scanf("%s %s", H, E);
        
        int lengthH = strlen(H), lengthE = strlen(E);

        int count = 0;
        if (lengthE == 1) {
            for (int i = 0; i < lengthH; i++) {
                if (H[i] == E[0]) count++;
            }
        } else {
            for (int i = 0; i < lengthH; i++) {
                int flag = 1;
                if (H[i] == E[0]) {
                    for (int j = 0; j < lengthE; j++) {
                        if (i + lengthE > lengthH) break;
                        if (H[i + j] != E[j]) {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag) {
                        count++;
                        i += lengthE - 1;
                    }
                }
            }
        }

        printf("Case #%d: %d\n", tc, count);
    }
    return 0;
}