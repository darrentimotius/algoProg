#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("Case #%d: ", i);
        
        if (A > B) {
            printf("Go-Jo\n");
        }else printf("Bi-Pay\n");
    }
    return 0;
}