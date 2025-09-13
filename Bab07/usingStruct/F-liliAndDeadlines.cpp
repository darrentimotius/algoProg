#include <stdio.h>
#include <string.h>

struct data{
    char mapel[15];
    int deadline;
};

void swap (data *a, data *b) {
    data temp = *a;
    *a = *b;
    *b = temp;
}

int partition (data dat[], int low, int high) {
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (dat[j].deadline < dat[high].deadline) {
            i++;
            swap(&dat[i], &dat[j]);
        } else if (dat[j].deadline == dat[high].deadline) {
            if (strcmp(dat[j].mapel, dat[high].mapel) < 0) {
                swap(&dat[j], &dat[high]);
            }
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
    int N;
    scanf("%d", &N);

    data dat[105];
    for (int i = 0; i < N; i++) {
        scanf("%s %d", dat[i].mapel, &dat[i].deadline);
    }

    quickSort(dat, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%s\n", dat[i].mapel);
    }
    return 0;
}