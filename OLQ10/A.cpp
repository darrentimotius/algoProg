#include <stdio.h>
#include <string.h>

struct data {
    char nama[300];
    int score;
};

int search(data dat[], int n, char a[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(dat[i].nama, a) == 0) return i;
    }
    return -1;
}

int binarySearch(data dat[], int l, int h, char target[]) {
    if (l > h) return -1;
    int m = l + (h - l) / 2;

    if (strcmp(target, dat[m].nama) == 0) return m;
    if (strcmp(target, dat[m].nama) > 0) return binarySearch(dat, m + 1, h, target);
    else return binarySearch(dat, l, m - 1, target);
}

int abs(int x) {
    if (x < 0) return -x;
    return x;
}

int main() {
    data dat[15005];

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d", dat[i].nama, &dat[i].score);
    }

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        char a[300], b[300];
        scanf("%s %s", a, b);

        // int idx1 = search(dat, n, a);
        // int idx2 = search(dat, n, b);

        int idx1 = binarySearch(dat, 0, n - 1, a);
        int idx2 = binarySearch(dat, 0, n - 1, b);

        if (strcmp(a, b) == 0) {
            puts("not valid");
        } else if (idx1 == -1 || idx2 == -1) {
            puts("not found");
        } else {
            int score = abs(dat[idx1].score - dat[idx2].score);
            int index = abs(idx1 - idx2);

            printf("%d %d\n", score, index);
        }
    }
    return 0;
}