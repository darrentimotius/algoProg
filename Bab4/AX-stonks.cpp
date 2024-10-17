#include <stdio.h>

int main() {
    long long int N, sum = 0;
    scanf("%lld", &N);
    for (long long int i = 1; i <= N; i++) {
        long long int A;
        scanf("%lld", &A);
        if (A > 0) sum += A;
    }
    printf("%lld", sum);
}

// int main(){long long int N,sum=0;scanf("%lld",&N);for(long long int i=1;i<=N;i++){long long int A;scanf("%lld",&A);if(A>0)sum+=A;}printf("%lld\n",sum);}