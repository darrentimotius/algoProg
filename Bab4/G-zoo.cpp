#include <stdio.h>

int main() {
    int N, sum = 0;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        int a;
        scanf("%d", &a);
        sum += a;
    }
    printf("%d\n", sum);
    return 0;
}