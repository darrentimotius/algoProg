#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    char pembilang[100][100] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};

    for (int tc = 0; tc < T; tc++) {
        int N;
        scanf("%d", &N);

        printf("Case #%02d: ", tc + 1);

        if (N == 0) {
            printf("nol\n");
            continue;
        }

        int ratusan = N / 100;
        int sisa = N % 100;
        int puluhan = sisa / 10;
        int satuan = sisa % 10;

        if (ratusan > 0) {
            if (ratusan == 1) printf("seratus");
            else printf("%s ratus", pembilang[ratusan]);
            if (sisa > 0) printf(" ");
        }

        if (sisa > 0) {
            if (sisa < 12) {
                printf("%s", pembilang[sisa]);
            } else if (sisa < 20) {
                printf("%s belas", pembilang[sisa % 10]);
            } else {
                printf("%s puluh", pembilang[puluhan]);
                if (satuan > 0) printf(" %s", pembilang[satuan]);
            }
        }

        printf("\n");
    }

    return 0;
}
