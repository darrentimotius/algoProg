#include <stdio.h>

/*
    Manual :
    FPB(48, 18) =   Faktor 48 = {1, 2, 3, 4, 6, 8, 12, 16, 24, 48}
                    Faktor 18 = {1, 2, 3, 6, 9, 18}
                    Yang sama = {1, 2, 3, 6}
                    Paling besar = 6

    Euclidean Algorithm :
    FPB(a, b) = FPB(b, a mod b)
    FPB(48, 18) = FPB(18, 48 mod 18)
                = FPB(18, 12)
    FPB(18, 12) = FPB(12, 18 mod 12)
                = FPB(12, 6)
    FPB(12, 6) = FPB(6, 12 mod 6)
                = FPB(6, 0)
                = 6
*/


int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    // Manual
    int min = (a < b) ? a : b;
    int fpb = 1;

    for (int i = 0; i <= min; i++) {
        if (a % i == 0 && b % i == 0) {
            fpb = i;
        }
    }

    printf("%d\n", fpb);

    // Euclidean
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    printf("%d\n", a);
    return 0;
}