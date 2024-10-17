#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%.2lf\n", (0.2 * a) + (0.3*b) + (0.5*c));
    return 0;
}