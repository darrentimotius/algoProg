#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    for (int i = 1; i <= T; i++) {
        int A, B;
        char C, D;
        
        scanf("%d:%d %c%c", &A, &B, &C, &D);
        printf("Case #%d: ", i);

        if (C == 'p' && A != 12 )
        printf("%02d:%02d\n", A + 12, B);
        else if (C == 'a' && A == 12)
        printf("%02d:%02d\n", A - 12, B);
        else
        printf("%02d:%02d\n", A, B);
    }
    return 0;
}