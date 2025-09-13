#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    // for (int i = 1; i <= T; i++) {
    //     int A, B;
    //     scanf("%d %d", &A, &B);
    //     printf("%d\n", ((A/B) << B));
    // }

    
    int A, B;
    scanf("%d %d", &A, &B);
    printf("%d\n", ((A/B) << B));

    scanf("%d %d", &A, &B);
    printf("%d\n", ((A/B) << B));

    scanf("%d %d", &A, &B);
    printf("%d\n", ((A/B) << B));
    return 0;
}