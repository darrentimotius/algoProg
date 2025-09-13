#include <stdio.h>

unsigned long long int binarySearch(unsigned long long int M, unsigned long long low, unsigned long long high) {
    while (low < high) {
        unsigned long long int mid = low + (high - low) / 2;
        unsigned long long int sum = mid * (mid + 1) * (2 * mid + 1) / 6;
        if (sum >= M) high = mid;
        else low = mid + 1;
    }
    return high;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        unsigned long long int M;
        scanf("%llu", &M);
        printf("Case #%d: %llu\n", tc, binarySearch(M, 1, 1500000));
    }
    return 0;
}