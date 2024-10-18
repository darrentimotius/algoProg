#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int maxWeapon = 0;
    for (int i = 0; i < N; i++) {
        int A;
        scanf("%d", &A);

        if (i == 0) maxWeapon = A;
        if (A > maxWeapon) maxWeapon = A;
    }

    int maxAttack = 0;
    for (int i = 0; i < M; i++) {
        int B;
        scanf("%d", &B);

        if (i == 0) maxAttack = B;
        if (B > maxAttack) maxAttack = B;
    }

    if (maxWeapon > maxAttack) printf("The dark secret was true\n");
    else printf("Secret debunked\n");
    return 0;
}