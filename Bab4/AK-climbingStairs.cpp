#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int temp = 0;
    scanf("%d", &temp);
    for (int i = 1; i < N; i++) {
        int A;
        scanf("%d", &A);

        if (A == 1) {
            printf("%d ", temp);
            temp = 0;
        }
        if (A > temp) temp = A;
    }
    printf("%d\n", temp);
    return 0;
}