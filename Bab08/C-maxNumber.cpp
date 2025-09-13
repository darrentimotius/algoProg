#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int arr[105];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < M; i++) {
        int temp;
        scanf("%d", &temp);

        int count = 0;
        for (int j = 0; j < N; j++) {
            if (arr[j] == temp) arr[j] = -1;
        }
    }

    int max = -1;
    for (int i = 0; i < N; i++) {
        if (arr[i] > max) max = arr[i];
    }

    printf("Maximum number is %d\n", max);
    return 0;
}