#include <stdio.h>

int change(int A, int B) {
    if (A == B) return 1;
    else if (A == 1) return 0;
    else if (A % 2 == 0) change(A / 2, B);
    else if (A % 2 == 1) change(A * 3 + 1, B);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int A, B;
        scanf("%d %d", &A, &B);

        printf("Case #%d: ", tc);
        if (change(A, B)) puts("YES");
        else puts("NO");
    }
    return 0;
}