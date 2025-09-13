#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("testdata.in", "r");

    int N;
    fscanf(file, "%d", &N); fgetc(file);
    // printf("%d\n", N);

    char nama[105][45], bunga[105][45];
    for (int i = 1; i <= N; i++) {
        fscanf(file, "%[^#]#%[^\n]", nama[i], bunga[i]); fgetc(file);
    }

    int T;
    fscanf(file, "%d", &T); fgetc(file);
    for (int tc = 1; tc <= T; tc++) {
        char input[45];
        fscanf(file, "%s", input); fgetc(file);

        printf("Case #%d: ", tc);
        int flag = 0;
        for (int i = 1; i <= N; i++) {
            if (strcmp(input, nama[i]) == 0) {
                printf("%s\n", bunga[i]);
                flag = 1;
            }
        }
        if (flag == 0) printf("N/A\n");
    }
    return 0;
}