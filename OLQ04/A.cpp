#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        char N[100001];
        scanf("%s", N);
        int totalGanjil = 0, totalGenap = 0;
        int panjangArray = strlen(N);

        for (int j = 0; j < panjangArray; j++) {
            if (j % 2 == 0) totalGenap += N[j] - '0';
            else totalGanjil += N[j] - '0';
        }

        printf("Case #%d: ", i);
        if ((totalGanjil - totalGenap) % 11 == 0) printf("Yeah\n");
        else printf("Nah\n");
    }
}