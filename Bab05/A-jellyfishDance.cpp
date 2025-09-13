#include <stdio.h>

int main() {
    int N, Q;
    int views[100];
    scanf("%d", &N);
    getchar();

    for (int i = 1; i <= N; i++) {
        scanf("%d", &views[i]);
    }

    scanf("%d", &Q);

    for (int i = 1; i <= Q; i++) {
        int A, B, sum = 0;
        scanf("%d %d", &A, &B);

        for (int j = A; j <= B; j++) {
            sum += views[j];
        }
        printf("Case #%d: %d\n", i, sum);
    }
    return 0;
}