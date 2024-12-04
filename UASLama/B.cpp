#include <stdio.h>
#include <string.h>

struct data {
    char s[100];
    int x;
};

void swap(data *a, data *b) {
    data temp = *a;
    *a = *b;
    *b = temp;
}

int partition(data dat[], int l, int h) {
    int i = l - 1;
    for (int j = l; j < h; j++) {
        if (dat[j].x < dat[h].x) {
            i++;
            swap(&dat[i], &dat[j]);
        }
    }
    swap(&dat[i + 1], &dat[h]);
    return i + 1;
}

void quick(data dat[], int l, int h) {
    if (l > h) return;

    int p = partition(dat, l, h);
    quick(dat, p + 1, h);
    quick(dat, l, p - 1);
}

int main() {
    int n;
    scanf("%d", &n);

    data dat[105];
    int count = 0;
    for (int i = 0; i < n; i++) {
        char s[100];
        int x;
        scanf("%s %d", s, &x);

        int found = -1;
        for (int j = 0; j < count; j++) {
            if (strcmp(s, dat[j].s) == 0) found = j;
        }

        if (found == -1) {
            strcpy(dat[count].s, s);
            dat[count].x = x;
            count++;
        } else {
            dat[found].x += x;
        }
    }

    quick(dat, 0, count - 1);
    for (int i = 0; i < count; i++) {
        printf("%s %d\n", dat[i].s, dat[i].x);
    }

    return 0;
}