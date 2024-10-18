#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        long long int sum = 0;
        scanf("%d", &N);
        
        for (int j = 1; j <= N; j++) {
            long long int barang;
            scanf("%lld", &barang);
            sum += barang;
        }
        printf("Case #%d: %lld\n", i, sum);
    }
    return 0;
}