#include <stdio.h>

int main() {
    int a, b, x;
    scanf("%d %d %d", &a, &b, &x);

    int c = x;
    int length = 1;
    while (c > 0) {
        c /= 10;
        length *= 10;
    }

    int count = 0;
    for (int i = a; i <= b; i++) {
        int d = i;
        while (d > 0) {
            if (d % length == x) {
                count++;
                printf("%d, ", i);
                break;
            }
            d /= 10;
        }
    }
    printf("\n%d\n", count);
    return 0;
}