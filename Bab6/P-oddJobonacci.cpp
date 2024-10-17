#include <stdio.h>

int jobo(int N) {
    if (N == 0 || N == 1) return N;
    if (N % 2 == 1) N = 1;
    else return jobo(N - 1) + jobo(N - 2);
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", jobo(N));
    return 0;
}