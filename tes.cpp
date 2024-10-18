#include <stdio.h>

int main() {
    FILE *file;
    file = fopen("testdata.in", "r");
    int N;
    fscanf(file, "%d\n", &N);

    char nama[200][200], random[200][200];
    int angka[200];
    for (int i = 0; i < N; i++) {
        fscanf(file, "%[^#]#%d#%[^\n]\n", nama[i], &angka[i], random[i]);
    }

    for (int i = 0; i < N; i++) {
        printf("%s %d %s\n", nama[i], angka[i], random[i]);
    }
    // fclose(file);
    return 0;
}