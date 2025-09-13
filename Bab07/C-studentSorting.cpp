#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("testdata.in", "r");

    int N = 0;
    fscanf(file, "%d", &N); fgetc(file);

    char nim[1005][11], nama[1005][25];
    for (int i = 0; i < N; i++) {
        fscanf(file, "%s %s", nim[i], nama[i]); fgetc(file);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            long long int temp1 = 0, temp2 = 0;
            sscanf(nim[j], "%lld", &temp1);
            sscanf(nim[j+1], "%lld", &temp2);
            if (temp1 > temp2) {
                char nimTemp[11], namaTemp[25];
                strcpy(nimTemp, nim[j]);
                strcpy(namaTemp, nama[j]);
                strcpy(nim[j], nim[j+1]);
                strcpy(nama[j], nama[j+1]);
                strcpy(nim[j+1], nimTemp);
                strcpy(nama[j+1], namaTemp);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%s %s\n", nim[i], nama[i]);
    }
    fclose(file);
}