#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int array[1005];
    int sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
        sum += array[i];
    }

    int max = (sum / N) * M / 100;
    
    int flag = -1;
    // printf("max = %d", max);
    for (int i = 0; i < N; i++) {
        if (array[i] > max) {
            printf("%d", i + 1);
            flag = 1;
            if (i != N - 1) printf(" ");
        }
    }

    if (flag == -1) printf("%d", 0);
    printf("\n");
    return 0;
}