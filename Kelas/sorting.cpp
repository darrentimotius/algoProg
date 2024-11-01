// Merge Sort
// Quick Sort

#include <stdio.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArr (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge (int arr[], int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int L[leftSize], R[rightSize]; // temporary array

    // isi array temp left
    for (int i = 0; i < leftSize; i++) {
        L[i] = arr[left + i];
    }

    // isi array temp kanan
    for (int i = 0; i < rightSize; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort
void mergeSort (int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid); // left side
        mergeSort(arr, mid+1, right); // right side

        merge(arr, left, mid, right);
    }
}

int main() {
    int numbers[] = {30, 50, 21, 9, 3, 8, 20, 45};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    puts("Before sort:");
    printArr(numbers, size);

    puts("After sort:");
    mergeSort(numbers, 0, size - 1);
    printArr(numbers, size);

    return 0;
}