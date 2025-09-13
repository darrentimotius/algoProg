#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    for (int i = a; i <= a + b; i++) {
        printf("%d\n", i);
    }
}