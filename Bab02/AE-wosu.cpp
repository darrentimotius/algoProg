#include <stdio.h>

int main() {
    long long int a, demeg = 0;
    scanf("%lld", &a);

    for (int i = 0; i < a; i++) {
        demeg += 100 + i * 50;
    }
    printf("%lld\n", demeg);
    return 0;
}