#include <stdio.h>
#include <string.h>

struct data {
    char kota[1005];
    double suhuAwal;
    double suhuCelcius;
    char satuan;
};

void swap(data *a, data *b) {
    data temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort
void bubbleSort(data dat[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (dat[j].suhuCelcius > dat[j+1].suhuCelcius) {
                swap(&dat[j], &dat[j+1]);
            } else if (dat[j].suhuCelcius == dat[j+1].suhuCelcius) {
                if (strcmp(dat[j].kota, dat[j+1].kota) > 0) {
                    swap(&dat[j], &dat[j+1]);
                }
            }
        }
    }
}

// quick sort
int partition(data dat[], int low, int high) {
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (dat[j].suhuCelcius < dat[high].suhuCelcius) {
            i++;
            swap(&dat[i], &dat[j]);
        } else if (dat[j].suhuCelcius == dat[high].suhuCelcius) {
            if (strcmp(dat[j].kota, dat[high].kota) < 0) {
                swap(&dat[j], &dat[high]);
            }
        }
    }
    swap(&dat[i+1], &dat[high]);
    return i + 1;
}

void quickSort(data dat[], int low, int high) {
    if (low < high) {
        int pivot = partition(dat, low, high);
        quickSort(dat, pivot + 1, high);
        quickSort(dat, low, pivot - 1);
    }
}

int main() {
    FILE *file = fopen("testdata.in", "r");

    int N = 0;
    data dat[105];
    while (!feof(file)) {
        fscanf(file, "%[^#]#%lf#%c\n", dat[N].kota, &dat[N].suhuAwal, &dat[N].satuan);
        N++;
    }

    for (int i = 0; i < N; i++) {
        if (dat[i].satuan == 'F') dat[i].suhuCelcius = (dat[i].suhuAwal - 32) * 5 / 9;
        else dat[i].suhuCelcius = dat[i].suhuAwal;
    }

    // bubbleSort(dat, N);
    quickSort(dat, 0, N - 1);
    for (int i = 0; i < N; i++) {
        printf("%s is %.2lf%c\n", dat[i].kota, dat[i].suhuAwal, dat[i].satuan);
    }

    return 0;
}