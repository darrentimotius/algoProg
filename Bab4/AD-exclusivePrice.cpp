#include <stdio.h>

int main() {
    long long int N, angka[1001];
    scanf("%lld", &N);

    // input angka
    for (long long int i = 0; i < N; i++) {
        scanf("%lld", &angka[i]);
    }

    // sort angka
    // bubble sort
    for (long long int i = 0; i < N; i++) {
        for (long long int j = 0; j < N-1; j++) {
            if (angka[j] > angka[j+1]) {
                long long int temp = angka[j];
                angka[j] = angka[j+1];
                angka[j+1] = temp;
            }
        }
    }

    // hitung berapa kali angka sama muncul berurutan
    // 1 5 3 4 4 5 5 5
    // 5 = 3 kali
    // 4 = 2 kali
    // maxCount = 3
    // count = 2

    // 1 5 3 5 5
    // 5 = 3 kali
    // count = 3
    long long int maxCount = 1, count = 1;
    for (long long int i = 0; i < N; i++) {
        if (angka[i] == angka[i - 1]) count++;
        else {
            if (count > maxCount) {
                maxCount = count;
            }
            count = 1;
        }
    }

    // cek lagi
    if (count > maxCount) {
        maxCount = count;
    }

    printf("%lld\n", maxCount);
    
    return 0;
}