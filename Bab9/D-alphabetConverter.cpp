#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("testdata.in", "r");

    int T;
    fscanf(file, "%d", &T); fgetc(file);
    for (int tc = 0; tc < T; tc++) {
        char X[105] = "";
        fscanf(file, "%[^\n]", X); fgetc(file);

        int l = strlen(X);

        char flag[105] = {0};
        int N;
        fscanf(file, "%d", &N); fgetc(file);

        for (int i = 0; i < N; i++) {
            char A, B;
            fscanf(file, "%c %c", &A, &B); fgetc(file);

            for (int j = 0; j < l; j++) {
                if (X[j] == A && flag[A - 'A'] == 0) X[j] = B;
            }
            flag[A - 'A'] = 1;
        }

        char flag2[105] = {0};
        for (int i = 0; i < l; i++) {
            flag2[X[i] - 'A']++;
        }

        for (int i = 0; i <= 25; i++) {
            if (flag2[i] == 0) continue;
            printf("%c %d\n", i + 'A', flag2[i]);
        }
    }
    return 0;
}