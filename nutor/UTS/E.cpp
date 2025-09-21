#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);

        char pembilang[100][100] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};

        int ribuan = 0, ratusan = 0, puluhan = 0, satuan = 0;
        satuan = N % 10;
        N /= 10;

        puluhan = (N % 10) * 10;
        if (puluhan < 12) {
            puluhan += satuan;
            satuan = 0;
        }
        N/= 10;

        ratusan = (N % 10) * 100;
        N/= 10;

        ribuan = (N % 10) * 1000;
        N /= 10;

        // printf("%d %d %d %d\n", ribuan, ratusan, puluhan, satuan);

        printf("Case #%0.02d: ", tc);
        if (ribuan > 0) {
            if (ribuan / 1000 == 1) printf("seribu");
            else printf("%s ribu", pembilang[ribuan / 1000]);
            if (ratusan == 0 && puluhan == 0 && satuan == 0) printf("\n");
            else printf(" ");
        }

        if (ratusan > 0) {
            if (ratusan / 100 == 1) printf("seratus");
            else printf("%s ratus", pembilang[ratusan / 100]);
            
            if (puluhan == 0 && satuan == 0) printf("\n");
            else printf(" ");
        }

        if (puluhan > 0) {
            if (puluhan >= 10 && puluhan < 13) printf("%s", pembilang[puluhan]);
            else if (puluhan < 20) printf("%s belas", pembilang[puluhan % 10]);
            else printf("%s puluh", pembilang[puluhan / 10]);

            if (satuan == 0) printf("\n");
            else printf(" ");
        }
        
        if (satuan > 0) {
            printf("%s", pembilang[satuan]);
            printf("\n");
        }
    }

    return 0;
}