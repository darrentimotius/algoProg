#include <stdio.h>

int main() {
    int testCase;
    scanf("%d", &testCase);
    
    for (int i = 1; i <= testCase; i++) {
        int baris, kolom;
        scanf("%d %d", &baris, &kolom);
        printf("Case #%d:\n", i);

        // Looping baris
        // j = baris
        for (int j = 1; j <= baris; j++) {
            // Looping kolom
            // k = kolom
            for (int k = 1; k <= kolom; k++) {
                if (j == 1 || j == baris || k == 1 || k == kolom) printf("#");
                else printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}