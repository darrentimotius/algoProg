#include <stdio.h>

int main() {
    long long int T;
    scanf("%lld", &T);

    for (long long int i = 1; i <= T; i++) {
        long long int N, M;
        scanf("%lld %lld", &N, &M);
        long long int hargaTermurah = 0;

        for (long long int j = 1; j <= N; j++) { // Looping ambil harga tiap permen
            long long int hargaPerPermen;
            scanf("%lld", &hargaPerPermen);
            
            // Masukin harga permen pertama buat jadi patokan
            if (j == 1) {
                hargaTermurah = hargaPerPermen;
            }
            // Kalo ada yang lebih murah lagi dari harga permen pertama, bakal ganti jadi harga yg lebih murah
            if (hargaPerPermen <= hargaTermurah) hargaTermurah = hargaPerPermen;
        }
        printf("Case #%lld: %lld\n", i, M / hargaTermurah);
    }
    return 0;
}