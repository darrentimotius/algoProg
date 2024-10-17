#include <stdio.h>

void func(int n, char a, char b) {
    if (n == 0) printf("%c", a);
    else if (n == 1) printf("%c", b);
    else {
        func(n - 1, a, b);
        func(n - 2, a, b);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int n;
        char a, b;
        scanf("%d %c %c", &n, &a, &b); getchar();

        printf("Case #%d: ", tc);
        func(n, a, b);
        printf("\n");
    }
    return 0;
}