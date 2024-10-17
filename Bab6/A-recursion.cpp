#include <stdio.h>

int kelipatan = 0;

int fun(int input) {
    if (input % 3 == 0 && input != 0) kelipatan++;
    if (input == 1) return 2;
    else if (input == 0) return 1;
    else if (input % 5 == 0) return input * 2;
    else return fun(input - 1) + input + fun(input - 2) + input - 2;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);

        kelipatan = 0;

        printf("Case #%d: %d ", tc, fun(N));
        printf("%d\n", kelipatan);
    }
    return 0;
}