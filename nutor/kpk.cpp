#include <stdio.h>

/*
    Hubungan KPK dan FPB :
    KPK(a, b) = (a * b) / FPB(a, b)
    KPK(48, 18) = (48 * 18) / 6
                = 144

    Manual :
    KPK(48, 18) =   Kelipatan 48 = {48, 96, 144, ...}
                    Kelipatan 18 = {18, 36, 54, 72, 90, 108, 126, 144, ...}
                    Kelipatan pertama yang sama / yang sama terkecil = 144
*/

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    // Manual
    int max = (a > b) ? a : b;
    int kpk = max;

    while (1) {
        if (kpk % a == 0 && kpk % b == 0) break;
        kpk += max;
    }

    printf("%d\n", kpk);

    // Pake rumus - cari fpbnya pake euclidean
    int x = a, y = b;
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    
    printf("%d\n", (a * b) / x);
    return 0;
}