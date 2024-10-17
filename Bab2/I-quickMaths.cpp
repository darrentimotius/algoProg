#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);

    printf("%d plus %d is %d\nminus one is %d\n", a, a, a+a, a+a-1);
    return 0;
}