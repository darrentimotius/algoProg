#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        unsigned long long int a, b;
        scanf("%llu %llu", &a, &b);
        printf("%llu\n", (a >> b) & 1);
    }
    return 0;
}