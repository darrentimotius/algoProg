#include <stdio.h>
#include <string.h>

struct data{
    char judul[1005];
    char nama[1005];
    int view;
};

void swap (data *a, data *b) {
    data temp = *a;
    *a = *b;
    *b = temp;
}

int partition (data dat[], int low, int high) {
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (dat[j].view > dat[high].view) {
            i++;
            swap(&dat[i], &dat[j]);
        }
    }
    swap(&dat[i+1], &dat[high]);
    return i + 1;
}

void quickSort (data dat[], int low, int high) {
    if (low >= high) return;
    int pivot = partition(dat, low, high);
    quickSort(dat, pivot + 1, high);
    quickSort(dat, low, pivot - 1);
}

int main() {
    FILE *file = fopen("testdata.in", "r");

    data dat[105];

    int counter = 0;
    while (!feof(file)) {
        fscanf(file, "%[^#]#%[^#]#%d\n", dat[counter].judul, dat[counter].nama, &dat[counter].view);
        counter++;
    }

    quickSort(dat, 0, counter - 1);

    for (int i = 0; i < counter; i++) {
        printf("%s by %s - %d\n", dat[i].judul, dat[i].nama, dat[i].view);
    }
    return 0;
}