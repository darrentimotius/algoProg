#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int R, H;
        scanf("%d %d", &R, &H);
        printf("Case #%d: %.2lf\n", i, 2 * 3.14 * R * (R + H));
    }
    return 0;
}