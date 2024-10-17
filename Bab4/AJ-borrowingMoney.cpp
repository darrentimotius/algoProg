#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int total = 0;
    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);
        total += A;
    }
    printf("%d\n", total);
    return 0;
}