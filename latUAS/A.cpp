#include <stdio.h>
#include <string.h>

struct data {
    char nama[105];
    char pass[25];
};

int main() {
    FILE *f = fopen("testdata.in", "r");

    int n;
    fscanf(f, "%d\n", &n);

    data dat[n+5];
    for (int i = 0; i < n; i++) {
        char temp[25];
        fscanf(f, "%[^#]#%[^\n]\n", dat[i].nama, temp);

        int l = strlen(temp);
        for (int j = 0; j < l; j++) {
            if ((j + 1) % 2 == 1) dat[i].pass[j] = temp[j] - (j + 1);
            else dat[i].pass[j] = temp[j] + (j + 1);
        }
        dat[i].pass[l] = '\0';
    }

    for (int i = 0; i < n; i++) {
        printf("%s - %s\n", dat[i].nama, dat[i].pass);
    }

    int t;
    fscanf(f, "%d\n", &t);

    for (int tc = 1; tc <= t; tc++) {
        char target[25];
        fscanf(f, "%s\n", target);

        printf("Case #%d: ", tc);
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (strcmp(target, dat[i].pass) == 0) {
                printf("%s\n", dat[i].nama);
                flag = 1;
                break;
            }
        }
        if (!flag) puts("Tidak Terdaftar");
    }
    return 0;
}