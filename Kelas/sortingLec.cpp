#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[k]) {
                k = j;
            }
        if (k != i) {
            swap(&arr[k], &arr[i]);
        }
        }
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void countingSort(int arr[], int n, int k) {
    int count[k+5];
    for (int i = 0; i < k + 5; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int m = 0;
    for (int i = 0; i < k + 5; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[m] = i;
            m++;
        }
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int temp[r + 5];
    i = l;
    j = m + 1;
    k = l;

    while (i <= m && j <= r) {
        if (arr[i] < arr[j]) { // kiri
            temp[k] = arr[i];
            k++;
            i++;
        } else { // kanan
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= m) { // copy sisa yang bagian kiri
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= r) { // copy sisa yang bagian kanan
        temp[k] = arr[j];
        k++;
        j++;
    }

    for ( i = l; i <= r; i++) { // copy balikin ke array awal
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int m = l + ((r - l) / 2);

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

int partition(int arr[], int low, int high) {
    int r = rand() % (high - low) + low;
    swap(&arr[r], &arr[high]);

    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &pivot);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;

    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}

int main() {
    // srand(time(0));
    int angka[100005];
    for (int i = 0; i < 100000; i++) {
        angka[i] = rand() % 100000 + 1;
        printf("%d, ", angka[i]);
    }
    printf("\n");
    // selectionSort(angka, 100000);
    // bubbleSort(angka, 100000);
    // countingSort(angka, 20, 100001);
    mergeSort(angka, 0, 99999);
    quickSort(angka, 0, 99999);
    for (int i = 0; i < 100000; i++) {
        printf("%d, ", angka[i]);
    }
    printf("\n");
    return 0;
}