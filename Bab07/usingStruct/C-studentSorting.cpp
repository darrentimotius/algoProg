#include <stdio.h>
#include <string.h>

struct data{
    char nim[15];
    char nama[25];
};

void swap (data *a, data *b) {
    data temp = *a;
    *a = *b;
    *b = temp;
}

int partition (data dat[], int low, int high) {
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (strcmp(dat[j].nim, dat[high].nim) < 0) {
            i++;
            swap(&dat[i], &dat[j]);
        }
    }

    swap(&dat[i + 1], &dat[high]);
    return i + 1;
}

void quickSort(data dat[], int low, int high) {
    if (low >= high) return;
    int pivot = partition(dat, low, high);
    quickSort(dat, pivot + 1, high);
    quickSort(dat, low, pivot - 1);
}

int main() {
    FILE *file = fopen("testdata.in", "r");

    int N;
    fscanf(file, "%d\n", &N);

    data dat[1005];
    for (int i = 0; i < N; i++) {
        fscanf(file, "%s %s\n", dat[i].nim, dat[i].nama);
    }

    quickSort(dat, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%s %s\n", dat[i].nim, dat[i].nama);
    }

    return 0;
}