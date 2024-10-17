#include <stdio.h>

int main() {
    // N = jumlah balon
    // P = kekuatan maksimal
    int N, P;
    scanf("%d %d", &N, &P);

    // hitung berapa balon yang bisa ditembak
    int count = 0;
    // input angka
    for (int i = 0; i < N; i++) { 
        int angka;
        scanf("%d", &angka);
        // cek apakah angka <= P
        if (angka < P) count++;
    }
    // output
    printf("%d\n", count);
    return 0;
}