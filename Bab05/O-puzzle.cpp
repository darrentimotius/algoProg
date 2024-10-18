#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int matrix[N+5][N+5];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int flag = 0;
    for (int i = 0; i < N; i++) {
        int temp = 0;
        for (int j = 0; j < N; j++) {
            temp = matrix[i][j];
            for (int k = 1; k < N; k++) {
                if (j + k >= N) break;
                if (matrix[i][j+k] == temp || matrix[j+k][i] == temp) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) break;
        }
        if (flag == 1) break;
    }

    if (flag == 1) printf("Nay\n");
    else if (flag == 0) printf("Yay\n");
    
    return 0;
}