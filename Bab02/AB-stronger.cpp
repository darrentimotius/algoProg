#include <stdio.h>

int main() {
    int hit, demeg;
    long long int sum = 0;
    scanf("%d", &hit);

    for(int i = 0; i < hit; i++) {
        demeg = 100 + i * 50;
        sum += demeg;
    }
    printf("%lld\n", sum);
    return 0;
}