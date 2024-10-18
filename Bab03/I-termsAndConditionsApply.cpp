#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        printf("Case #%d: ", i);
        
        if (a * b/100 > c) {
            printf("%d\n", c);
        } else printf("%d\n", a * b/100);
    }
    return 0;
}