#include <stdio.h>
#include <string.h>

int fibo (int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (n % 3 == 0) return 10;
    else return fibo(n - 1) + fibo(n - 2);
}

// int main(){
//     int n;
//     scanf("%d", &n);

//     unsigned long long fib[10005];
//     fib[0] = 0, fib[1] = 1;

//     if (n == 1) printf("0\n");
// 	else if (n==2) printf("0 1\n");
// 	else {
//         printf("%llu %llu ", fib[0], fib[1]);

//         for(int i=2;i<n;i++) {
//             if(i%3==0) fib[i] = 10;
//             else fib[i] = fib[i-1] + fib[i-2];

//             printf("%llu", fib[i]);
//             if(i!=n-1) printf(" ");
//     }
//     printf("\n");
//     }
//     return 0;
// }

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("%d", fibo(i));
        if (i != n - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}