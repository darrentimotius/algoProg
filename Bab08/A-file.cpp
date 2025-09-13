#include <stdio.h>
#include <string.h>

void searching(char source[][55], char target[][55], char change[], int T) {
    for (int i = 0; i < T; i++) {
        if (strcmp(source[i], change) == 0) {
            printf("%s", target[i]);
            return;
        }
        // else if (strcmp(target[i], change) == 0) {
        //     printf("%s", change);
        //     return;
        // }
    }
    printf("%s", change);
    return;
}

int main() {
    FILE *file = fopen("testdata.in", "r");

    int T;
    fscanf(file, "%d\n", &T);
    char source[105][55], target[105][55];

    for (int i = 0; i < T; i++) {
        fscanf(file, "%[^#]#%s\n", source[i], target[i]);
    }

    int TC;
    fscanf(file, "%d\n", &TC);

    for (int i = 1; i <= TC; i++) {
        char sentences[105];
        fscanf(file, "%[^\n]\n", sentences);
        int l = strlen(sentences);

        char temp[105] = "";
        int counter = 0;

        printf("Case #%d:\n", i);

        for (int j = 0; j <= l; j++) {
            if (sentences[j] == ' ' || sentences[j] == '\0') {
                temp[counter] = '\0';
                searching(source, target, temp, T);

                if (sentences[j] == ' ') printf(" ");
                else printf("\n");

                counter = 0;
            }
            else {
                temp[counter] = sentences[j];
                counter++;
            }
        }
    }
    return 0;
}