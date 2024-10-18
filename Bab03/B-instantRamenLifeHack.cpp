#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        printf("Case #%d: ", i);
        if (b + c < a) {
            printf("no\n");
        } else {
            printf("yes\n");
        }
    }
    return 0;
}