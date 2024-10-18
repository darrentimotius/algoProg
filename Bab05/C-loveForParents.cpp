#include <stdio.h>

int main() {
    int jumlahItem, testCase, a, b;
    int A[100001];
    scanf("%d", &jumlahItem);
    getchar();

    for (int i = 0; i < jumlahItem; i++) {
        scanf("%d", &A[i]);
        getchar();
    }

    scanf("%d", &testCase);
    getchar();

    for (int j = 0; j < testCase; j++) {
        scanf("%d %d", &a, &b);
        getchar();

        A[a-1] = b;

        printf("Case #%d: ", j+1);

        for (int k = 0; k < jumlahItem; k++) {
            printf("%d", A[k]);
            if (k < jumlahItem-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}