#include <stdio.h>
#include <string.h>

struct data {
    char name[100];
    char pass[100];
};

void search(data dat[], char inp[], int n) {
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(dat[i].pass, inp) == 0) {
            printf("%s\n", dat[i].name);
            flag = 1;
            break;
        }
    }
    if (!flag) puts("Tidak terdaftar");
}

int main() {
    FILE *f = fopen("testdata.in", "r");

    int n;
    fscanf(f, "%d\n", &n);

    data dat[n + 5];
    for (int i = 0; i < n; i++) {
        fscanf(f, "%[^#]#%s\n", dat[i].name, dat[i].pass);
    }

    int t;
    fscanf(f, "%d\n", &t);
    for (int tc = 1; tc <= t; tc++) {
        char temp[100];
        fscanf(f, "%s\n", temp);
        
        int l = strlen(temp);

        for (int i = 0; i < l; i++) {
            if ((i + 1) % 2 == 0) {
                temp[i] -= (i + 1);
            } else if ((i + 1) % 2 == 1) {
                temp[i] += (i + 1);
            }
        }
        printf("Case #%d: ", tc);
        search(dat, temp, n);
    }
    return 0;
}