#include <stdio.h>

int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    long long int sum = 0;

    for (int i = A; i <= B; i++) {
        sum += i;
    }
    printf("%lld\n", sum);
    return 0;
}