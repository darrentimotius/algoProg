#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int index[N+1];
    for (int i = 0; i < N; i++) {
        scanf("%d", &index[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (index[j] > index[j+1]) {
                int temp = index[j];
                index[j] = index[j+1];
                index[j+1] = temp;
            }
        }
    }

    int count = 1, temp = index[0];
    for (int i = 0; i < N; i++) {
        if (index[i] != temp) {
            count++;
            temp = index[i];
        }
    }

    printf("%d\n", count);
    return 0;
}