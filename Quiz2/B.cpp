#include <stdio.h>
#include <string.h>

int main() {
    FILE *f = fopen("testdata.in", "r");

    int n;
    fscanf(f, "%d\n", &n);

    long long int kata[50] = {0};
    char s[2000];
    int count = 0;
    int countLembar = 0;
    int flag = 0;
    while (fscanf(f, "%s\n", s) != EOF) {
        if (strcmp(s, "#") == 0) {
            // printf("ketemu #\n");
            if (kata[countLembar] < n) {
                flag = 1;
            }
            countLembar++;
            continue;
        }
        kata[countLembar]++;
    }

    // for (int i = 0; i < count; i++) {
    //     // printf("i : %d, lembar : %d\n", i, countLembar);
    //     if (strcmp(s[i], "#") == 0) {
    //         // printf("ketemu #\n");
    //         if (kata[countLembar] < n) {
    //             flag = 1;
    //         }
    //         countLembar++;
    //         continue;
    //     }
    //     int l = strlen(s[i]);
    //     for (int j = 0; j <= l; j++) {
    //         if (s[i][j] == ' ' || s[i][j] == '\0' || s[i][j] == '\n') {
    //             kata[countLembar]++;
    //             // printf("ketemu spasi atau null\n");
    //         }
    //     }
    // }

    if (!flag) {
        puts("The essay is correct");
        return 0;
    }

    int c = 1;
    for (int i = 0; i < countLembar; i++) {
        if (kata[i] < n) printf("page %d: %lld word(s)\n", i + 1, kata[i]);
        
        // printf("%d %d\n", i + 1, kata[i]);
    }
    return 0;
}