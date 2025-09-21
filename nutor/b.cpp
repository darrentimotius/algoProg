#include <stdio.h>

int main() {
    int satuan = 0, puluhan = 0, ratusan = 0, x;
    scanf("%d", &x); getchar();

    char map[100][100] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};
    satuan = x % 10;
    x /= 10;

    puluhan = (x % 10) * 10;
    x /= 10;

    ratusan = (x % 10) * 100;
    x /= 10;

    if ((puluhan + satuan) > 9 && (puluhan + satuan) < 20) {
        puluhan += satuan;
        satuan = 0;
    } 

    // printf("%d %d %d\n", ratusan, puluhan, satuan);

    if (ratusan > 0) {
        if (ratusan == 100) printf("seratus");
        else {
            printf("%s ratus", map[ratusan / 100]);
        }
        if (!puluhan && !satuan) printf("\n");
        else printf(" ");
    }

    if (puluhan > 0) {
        if (puluhan > 9 && puluhan < 12) printf("%s", map[puluhan]);
        else if (puluhan < 20) printf("%s belas", map[puluhan % 10]);
        else printf("%s puluh", map[puluhan / 10]);
        if (!satuan) printf("\n");
        else printf(" ");
    }

    if (satuan > 0) {
        printf("%s\n", map[satuan]);
    }
    return 0;
}