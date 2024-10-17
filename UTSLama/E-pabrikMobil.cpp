#include <stdio.h>

int main() {
    int ban, pintu, kaca, mobil = 0;
    scanf("%d %d %d", &ban, &pintu , &kaca);

    while (ban > 0 || pintu > 0 || kaca > 0) ban -= 4, pintu -= 2, kaca -= 1, mobil++;

    if (ban < 0) ban = -ban;
    if (pintu < 0) pintu = -pintu;
    if (kaca < 0) kaca = -kaca;
    
    printf("%d %d %d %d\n", mobil, ban, pintu, kaca);
    return 0;
}