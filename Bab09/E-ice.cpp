#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("testdata.in", "r");

    int T;
    fscanf(file, "%d", &T); fgetc(file);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        fscanf(file, "%d", &N); fgetc(file);

        int array[N+5] = {0};
        int sum = 0;
        for (int i = 0; i < N; i++) {
            fscanf(file, "%d", &array[i]); fgetc(file);
            sum += array[i];
        }

        // luas
        int luas = sum * 4;

        // keliling
        int palingBawahAtas = N * 4;
        int keAtas = 0;
        int kiri = 2 * array[0];
        int kanan = 2 * array[N - 1];

        if (N != 1) {
            for (int i = 0; i < N - 1; i++) {
                int temp = array[i] - array[i+1];
                if (temp < 0) temp *= -1;
                keAtas += temp * 2;
            }
        }
        keAtas += kiri + kanan;
        int keliling = palingBawahAtas + keAtas;

        printf("Case #%d: %d %d\n", tc, keliling, luas);
    }
    return 0;
}