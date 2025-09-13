#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data {
    char name[55];
    int num;
};

void swap(data *a, data *b) {
    data temp = *a;
    *a = *b;
    *b = temp;
}

int partition(data dat[], int low, int high) {
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (dat[j].num > dat[high].num) {
            i++;
            swap(&dat[i], &dat[j]);
        } else if (dat[j].num == dat[high].num) {
            if (strcmp(dat[j].name, dat[high].name) < 0) {
                swap(&dat[j], &dat[high]);
            }
        }
    }
    swap(&dat[i + 1], &dat[high]);
    return i + 1;
}

void quickSort(data dat[], int low, int high) {
    if (low >= high) return;

    int pi = partition(dat, low, high);
    quickSort(dat, low, pi - 1);
    quickSort(dat, pi + 1, high);
}


int main() {
    int T;
    scanf("%d", &T); getchar();

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N); getchar();

        data dat[55];
        for (int i = 0; i < N; i++) {
            scanf("%[^#]#%d", dat[i].name, &dat[i].num);
            getchar();
        }

        quickSort(dat, 0, N - 1);

        printf("Case #%d:\n", tc);
        for (int i = 0; i < N; i++) {
            printf("%s - %d\n", dat[i].name, dat[i].num);
        }
    }
    return 0;
}