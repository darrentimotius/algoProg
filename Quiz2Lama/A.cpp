#include <stdio.h>
#include <string.h>

#define gc getchar();

struct data {
    char num[260];
    char name[260];
};

int binSearch(data dat[], int l, int h, char target[]) {
    if (l > h) return -1;
    int m = l + (h - l) / 2;
    if (strcmp(dat[m].num, target) == 0) return m;
    else if (strcmp(dat[m].num, target) > 0) return binSearch(dat, l, m - 1, target);
    else return binSearch(dat, m + 1, h, target);
}

int main() {
    int t;
    scanf("%d", &t); gc

    data dat[10005];
    for (int i = 0; i < t; i++) {
        scanf("%s %[^\n]", dat[i].num, dat[i].name); gc
    }

    char target1[260], target2[260];
    scanf("%s", target1); gc
    scanf("%s", target2); gc

    if (strcmp(target1, target2) == 0 ) {
        puts("Impossible");
        return 0;
    } else {
        int a = binSearch(dat, 0, t - 1, target1);
        int b = binSearch(dat, 0, t - 1, target2);

        printf("%s is calling %s\n", dat[a].name, dat[b].name);
    }

    return 0;
}