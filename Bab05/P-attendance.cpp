#include <stdio.h>

int main() {
    long long int N;
    scanf("%lld", &N);

    long long int matrix[N+5][N+5];
    for (long long int i = 0; i < N; i++) {
        for (long long int j = 0; j < N; j++) {
            scanf("%lld", &matrix[i][j]);
        }
    }

    long long int team[N+5] = {0};
    for (long long int i = 0; i < N; i++) {
        for (long long int j = 0; j < N; j++) {
            if (matrix[i][j] > 0) {
                team[matrix[i][j]]++;
            }
        }
    }

    long long int count = 0;
    for (long long int i = 1; i <= N; i++) {
        if (team[i] < N) count++; 
    }

    printf("%lld\n", count);
    return 0;
}