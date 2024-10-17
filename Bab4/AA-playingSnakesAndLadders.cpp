#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    int hasil = 0;

    for (int i = 1; i <= T; i++) {
        int dadu;
        scanf("%d", &dadu);
        hasil += dadu;

        if (hasil == 9) hasil = 21;
        else if (hasil == 33) hasil = 42;
        else if (hasil == 53) hasil = 37;
        else if (hasil == 76) hasil = 92;
        else if (hasil == 80) hasil = 59;
        else if (hasil == 97) hasil = 88;
    }
    printf("%d\n", hasil);
    return 0;
}