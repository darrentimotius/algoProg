#include <stdio.h>

int main() {
    int N, j, l, b;
    scanf("%d", &N);
    scanf("%d %d %d", &j, &l, &b);

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        int orgLain;
        scanf("%d", &orgLain);
        sum += orgLain;
    }

    int rataRata = (j+l+b+sum) / (N+3);
    if (j < rataRata) printf("Jojo tidak lolos\n");
    else printf("Jojo lolos\n");

    if (l < rataRata) printf("Lili tidak lolos\n");
    else printf("Lili lolos\n");

    if (b < rataRata) printf("Bibi tidak lolos\n");
    else printf("Bibi lolos\n");
    return 0;
}