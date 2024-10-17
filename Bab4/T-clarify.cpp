#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int count = 0;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (b > c) count++;
    }
    printf("%d\n", count);
}