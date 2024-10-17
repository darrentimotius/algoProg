#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int count = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            int temp = N - i - j;
            if (temp >= 0) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}