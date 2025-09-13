#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    // test case
    for (int i = 1; i <= T; i++) {
        int a;
        scanf("%d", &a);
        printf("Case #%d:\n", i);

        // buat pattern per case
        if ((a * a) % 2 == 0) {
            //Looping baris
        for (int j = 1; j <= a; j++) {
            // Looping kolom
            //spasi
            for (int k = 1; k <= a-j; k++) printf(" ");
            // pagar bintang
            for (int k = 0; k <= j-1; k++) {
                if(k % 2 == 0) printf("#");
                else printf("*");
            }
            printf("\n");
        }
        } else {
            for (int j = 1; j <= a; j++) {
            //spasi
            for (int k = 1; k <= a-j; k++) printf(" ");
            // bintang pagar
            for (int k = 0; k <= j-1; k++) {
                if(k % 2 == 0) printf("*");
                else printf("#");
            }
            printf("\n");
        }
        }
    }
}