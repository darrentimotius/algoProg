#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int index[N+5];
    for (int i = 0; i < N; i++) {
        scanf("%d", &index[i]);
    }

    int arr[N+5];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int ans[N+5];
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N - 1; j++) {
    //         if (index[j] > index[j+1]) {
    //             int temp = index[j];
    //             int temp1 = arr[j];
    //             index[j] = index[j+1];
    //             arr[j] = arr[j+1];
    //             index[j+1] = temp;
    //             arr[j+1] = temp1;
    //         }
    //     }
    // }
    for (int i = 0; i < N; i++) {
        ans[index[i]] = arr[i];
    }

    for (int i = 0; i < N; i++) {
        printf("%d", ans[i]);
        if (i != N - 1) printf(" ");
    }
    printf("\n");
    return 0;
}