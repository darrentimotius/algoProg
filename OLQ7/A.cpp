// #include <stdio.h>

// long long int pohon(int M) {
//     long long int branch = 0;
//     if (M == 0) branch = 0;
//     long long int temp = 0;
//     temp += M * 2;
//     temp *= 2;
//     branch += temp;
//     temp = 0;
//     M--;
//     return branch;
// }

// #define mod 1000000000;
// int main() {
//     int T;
//     scanf("%d", &T); getchar();

//     for (int tc = 1; tc <= T; tc++) {
//         int M, N;
//         scanf("%d %d", &M, &N); getchar();
//         long long int cabang = 0;
//         // if (N > 1) {
//             long long int temp = pohon(M) * 2;
//             cabang = temp + (N - 1) + M;
//             cabang = cabang % mod;
//         // } else cabang = M + M;
//         printf("Case #%d: %lld\n", tc, cabang);
//     }
//     return 0;
// }

#include <stdio.h>
#define ll long long

ll tree(ll M, ll N) {
    if (M == 0) return 0;
    return M + (N - 1) + (N - 1) * tree(M - 1, N - 1) % 1000000000;
}

int main() {
    int T;
    scanf("%d", &T);
    
    for (int tc = 1; tc <= T; tc++) {
        int M, N;
        scanf("%d %d", &M, &N);
        printf("Case #%d: %lld\n", tc, tree(M, N));
    }
    return 0;
}