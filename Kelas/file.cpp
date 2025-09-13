#include <stdio.h>

void tulis() {
    FILE *f = fopen("test.txt", "w");
    char nama[100];
    int nilai, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %[^\n]", &nilai, nama); getchar();
        fprintf(f, "%s, %d\n", nama, nilai);
    }
    // fprintf(f, "Hello %s..\n", nama);
    // fprintf(f, "Nilai: %d\n", nilai);
    fclose(f);
}

void baca() {
    FILE *fin = fopen("test.txt", "r");
    if (fin == NULL) {
        printf("File not found.\n");
        return;
    }

    char nama[100];
    int nilai;
    for (int i = 0; i < 9; i++) {
        fscanf(fin, "%[^,],%d\n", nama, &nilai);
        printf("%d %s\n", nilai, nama);
    }
    fclose(fin);
}

int main() {
    // tulis();
    baca();
    return 0;
}