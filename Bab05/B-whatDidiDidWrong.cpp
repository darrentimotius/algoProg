#include <stdio.h>

int main() {
    int T;
    int A[100001];
    int B[100001];
    int hasil[100001];
    scanf("%d", &T);
    
    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        for (int l = 0; l < N; l++) {
            scanf("%d", &A[l]);
        }

        for (int j = 0; j < N; j++){
            scanf("%d", &B[j]);
        }

        printf("Case #%d: ", i);

        for (int k = 0; k < N; k++) {
            hasil[k] = A[k] - B[k];
            printf("%d", hasil[k]);
            if (k < N-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}