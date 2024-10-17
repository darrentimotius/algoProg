#include <stdio.h>

int main() {
    int T, N;
    scanf("%d", &T); getchar();

    for (int i = 1; i <= T; i++) {
        int slice;
        scanf("%d", &slice); getchar();
        printf("Case %d: ", i);

        int temp = 1;
        for (int j = 0; j <= slice - 1; j++) {
            printf("%d", temp + j);
            temp = temp + j;
            if (j < slice - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}