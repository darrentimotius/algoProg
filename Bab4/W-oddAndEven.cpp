#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N = 0;
        scanf("%d", &N);
        int odd = 0, even = 0;
        for (int j = 0; j < N; j++) {
            int A;
            scanf("%d", &A);

            if (A % 2 == 0) even ++;
            else odd ++;
        }
        printf("Odd group : %d integer(s).\nEven group : %d integer(s).\n\n", odd, even);
    }
    return 0;
}