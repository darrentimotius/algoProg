#include <stdio.h>

int a, b;

int fibo(int k) {
    if (k == 0) return a;
    if (k == 1) return b;
    else return fibo(k - 1) + fibo(k - 2);
}

int main() {
    int k;
    scanf("%d %d", &a, &b);
    scanf("%d", &k);

    printf("%d\n", fibo(k));
    return 0;
}