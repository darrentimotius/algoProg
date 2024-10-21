#include <stdio.h>
#include <string.h>

void searching(char nim[][11], char name[][21], char temp[], int N) {
    for (int i = 0; i < N; i++) {
        if (strcmp(nim[i], temp) == 0) {
            printf("%s\n", name[i]);
            return;
        }
    }
    printf("N/A\n");
    return;
}

int main() {
    FILE *file = fopen("testdata.in", "r");

    int N;
    fscanf(file, "%d\n", &N);

    char nim[105][11], name[105][21];
    for (int i = 0; i < N; i++) {
        fscanf(file, "%s %[^\n]\n", nim[i], name[i]);
    }

    int T;
    fscanf(file, "%d\n", &T);

    for (int tc = 1; tc <= T; tc++) {
        char temp[15];
        fscanf(file, "%s\n", temp);

        printf("Case #%d: ", tc);
        searching(nim, name, temp, N);
    }

    fclose(file);
    return 0;
}