#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int A, B, C, D, E, F;
        scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);
        printf("Case #%d: ", i);
        for (int j = 0; j < A; j++) printf("a");
        for (int j = 0; j < B; j++) printf("s");
        for (int j = 0; j < C; j++) printf("h");
        for (int j = 0; j < D; j++) printf("i");
        for (int j = 0; j < E; j++) printf("a");
        for (int j = 0; j < F; j++) printf("p");
        printf("\n");
    }
}