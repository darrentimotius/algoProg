#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct data {
    int r;
    char a[15];
    char rank[105];
};

void swap(data *a, data *b) {
    data temp = *a;
    *a = *b;
    *b = temp;
}

int partition(data dat[], int low, int high) {
    // int r = rand() % (high - low) + low;
    // swap(&dat[r], &dat[high]);

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (dat[j].r > dat[high].r) {
            i++;
            swap(&dat[i], &dat[j]);
        } else if (dat[j].r == dat[high].r) {
            if (strcmp(dat[j].a, dat[high].a) < 0) {
                i++;
                swap(&dat[i], &dat[j]);
            }
        }
    }
    swap(&dat[i + 1], &dat[high]);
    return i + 1;
}

void quick(data dat[], int low, int high) {
    if (low >= high) return;

    int p = partition(dat, low, high);
    quick(dat, low, p - 1);
    quick(dat, p + 1, high);
}

data dat[100005];

int main() {
    int p;
    scanf("%d", &p);

    int avg = 0;
    for (int i = 0; i < p; i++) {
        scanf("%d %s", &dat[i].r, dat[i].a);
        avg += dat[i].r;
        if (dat[i].r <= 200) strcpy(dat[i].rank, "Ascend");
        else if (dat[i].r <= 350) strcpy(dat[i].rank, "Mortal");
        else if (dat[i].r <= 500) strcpy(dat[i].rank, "Radial");
    }

    avg /= p;
    quick(dat, 0, p - 1);
    for (int i = 0; i < p; i++) {
        printf("%s %d %d %s\n", dat[i].rank, dat[i].r, dat[i].r - avg, dat[i].a);
    }
    return 0;
}