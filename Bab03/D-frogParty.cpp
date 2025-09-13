#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        // Filling slots
        if ((a * b) % 2 == 0)
        printf("Case #%d: Party time!\n", i);
        else
        printf("Case #%d: Need more frogs\n", i);
    }
    return 0;
}