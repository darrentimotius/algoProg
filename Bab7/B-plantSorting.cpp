#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("testdata.in", "r");

    int N;
    fscanf(file, "%d", &N); fgetc(file);

    char nama[1005][45];
    long long int angka[1005];
    for (int i = 0; i < N; i++) {
        fscanf(file, "%lld#%[^\n]\n", &angka[i], nama[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (strcmp(nama[j], nama[j+1]) > 0) {
                char temp[45];
                strcpy(temp, nama[j]);
                strcpy(nama[j], nama[j+1]);
                strcpy(nama[j+1], temp);

                long long int tempAngka = angka[j];
                angka[j] = angka[j+1];
                angka[j+1] = tempAngka;
            }
        }
    }


    for (int i = 0; i < N; i++) {
        printf("%lld %s\n", angka[i], nama[i]);
    }
    fclose(file);
    return 0;
}