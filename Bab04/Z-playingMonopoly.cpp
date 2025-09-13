#include <stdio.h>

int main() {
    int T, hasil = 0;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        int dadu;
        scanf("%d", &dadu);
        hasil += dadu;

        if(hasil == 12) {
            hasil = 28;
        } else if (hasil == 30) {
            hasil = 10;
        } else if (hasil == 35) {
            hasil = 7;
        } else if (hasil >= 40) {
            hasil = hasil - 40;
        }
    }
    
    printf("%d\n", hasil);
    return 0;
}