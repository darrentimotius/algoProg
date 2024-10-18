#include <stdio.h>

void branch(int A[105], int N, int index, int sum) {
    int manyBranch = 0;
    sum += A[index];
    if (index * 2 <= N) {
        branch(A, N, index * 2, sum);
        manyBranch++;
    }
    if (index * 2 + 1 <= N) {
        branch(A, N, index * 2 + 1, sum);
        manyBranch++;
    }
    if (manyBranch == 0) printf("%d\n", sum);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);

        int A[105];
        for (int i = 1; i <= N; i++) {
            scanf("%d", &A[i]);
        }
        
        int index = 1, sum = 0;
        printf("Case #%d:\n", tc);
        branch(A, N, index, sum);
    }
    return 0;
}