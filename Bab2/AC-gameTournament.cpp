#include <stdio.h>
int main (){
    unsigned long long int N;
    scanf("%llu", &N);
    getchar();

    printf("%llu\n", (1llu << N) - 1);
}