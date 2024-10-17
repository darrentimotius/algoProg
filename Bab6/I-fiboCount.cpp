#include <stdio.h>

int count = 0;

int fibo(int n) {
    count++;

    if (n == 0 || n ==  1) return 1;

    return fibo(n - 1) + fibo(n - 2);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        fibo(n);

        printf("Case #%d: ", tc);
        printf("%d\n", count);
        
        count = 0;
    }
    return 0;
}