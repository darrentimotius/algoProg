#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);
        int arr[N+5];

        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[j]);
        }

        printf("Case #%d: ", i);
        for (int j = N - 1; j >= 0; j--) {
            if (j != N - 1) printf(" ");
            printf("%d", arr[j]);
        }
        printf("\n");
    }
    return 0;
}