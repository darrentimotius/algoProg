#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T); getchar();

    for (int tc = 0; tc < T; tc++) {
        char H[1005], E[1005];
        scanf("%s %s", H, E); getchar();
        
        int lH = strlen(H), lE = strlen(E);
        int count = 0;

        if (lE == 1) {
            for (int i = 0; i < lH; i++) {
                if (H[i] == E[0])
                    count++;
            }
        } else {
            for (int i = 0; i < lH; i++) {
                int flag = 1;
                printf("i = %d\n", i);
                if (H[i] == E[0]) {
                    printf("masuk forloop\n");
                    for (int j = 0; j < lE; j++) {
                        if (i + lE > lH) break;
                        if (H[i + j] != E[j]) {
                            flag = 0;
                            break;
                        }
                        if (H[i + j] == E[j]) {
                            printf("di H[%d] dan E[%d], %c = %c\n", i + j, j, H[i + j], E[j]);
                        }
                    }
                    if (flag) count++;
                    if (flag) printf("ada yang sama di i ke %d\n", i);
                    if (flag) i += lE - 1;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}