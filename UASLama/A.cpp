#include <stdio.h>
#include <string.h>

struct data {
    char nama[35];
    int x;
    int price;
};

int main() {
    FILE *f = fopen("testcase.in", "r");

    int n;
    fscanf(f, "%d\n", &n);

    data dat[105];
    int count = 0;
    for (int i = 0; i < n; i++) {
        char nama[35];
        int x;
        fscanf(f, "%[^#]#%d\n", nama, &x);

        int found = -1;
        for (int j = 0; j < count; j++) {
            if (strcmp(nama, dat[j].nama) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {
            strcpy(dat[count].nama, nama);
            dat[count].x = x;
            count++;
        } else dat[found].x += x;
    }

    char target[35];
    fscanf(f, "%s\n", target);

    int xTarget = 0;
    for (int i = 0; i < count; i++) {
        // convert ml jadi harga
        if (dat[i].x > 591) dat[i].price = 70000;
        else if (dat[i].x > 473) dat[i].price = 60000;
        else if (dat[i].x > 354) dat[i].price = 57000;
        else dat[i].price = 53000;

        // print daftar customer
        printf("%s - %d\n", dat[i].nama, dat[i].price);

        // searching target
        if (strcmp(dat[i].nama, target) == 0) xTarget = dat[i].x;
    }

    //print target
    printf("%s - %d\n", target, xTarget);
    fclose(f);
    return 0;
}