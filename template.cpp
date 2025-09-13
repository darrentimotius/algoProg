#include <stdio.h>
#include <stdlib.h>

// melakukan swap antara 2 integer
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort
void bubbleSort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j+1]) swap(&array[j], &array[j+1]);
        }
    }
}

// print bubble sort
void printBubbleSort(int array[], int n) {
    bubbleSort(array, n);

    printf("Array setelah di bubble sort : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// quick sort
int partition(int array[], int low, int high) { // melakukan sorting berdasarkan pivot
    
    // random pivot
    int r = rand() % (high - low) + low;
    swap(&array[r], &array[high]);

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] < array[high]) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[high]);
    return i + 1; // balikin lokasi pivotnya
}

void quickSort(int array[], int low, int high) {
    if (low < high) { // lakuin geser pivot kalo masih belum ketemu di tengah
        int pivot = partition(array, low, high);
        quickSort(array, low, pivot - 1); // geser pivot dari kanan sampe ke tengah
        quickSort(array, pivot + 1, high); // geser pivot dari kiri sampe ke tengah
    }
}

// print quick sort
void printQuickSort(int array[], int low, int high, int n) {
    quickSort(array, low, high);

    printf("Array setelah di quick sort : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// merge sort
void merge(int array[], int left, int mid, int right) {
    int i, j, k;
    int temp[right + 5];
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right) {
        if (array[i] < array[j]) { // kiri
            temp[k] = array[i];
            k++;
            i++;
        } else { // kanan
            temp[k] = array[j];
            k++;
            j++;
        }
    }

    while (i <= mid) { // copy sisa yang bagian kiri
        temp[k] = array[i];
        k++;
        i++;
    }

    while (j <= right) { // copy sisa yang bagian kanan
        temp[k] = array[j];
        k++;
        j++;
    }

    for ( i = left; i <= right; i++) { // copy balikin ke array awal
        array[i] = temp[i];
    }
}

void mergeSort(int array[], int left, int right) {
    if (left >= right) return;
    int mid = left + ((right - left) / 2);

    mergeSort(array, left, mid); // rekursi sebelah kirinya mid
    mergeSort(array, mid + 1, right); // rekursi sebelah kanannya mid
    merge(array, left, mid, right); // sort per bagian
}

// print merge sort
void printMergeSort(int array[], int left, int right, int n) {
    mergeSort(array, left, right);

    printf("Array setelah di merge sort : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

// binary search
int binarySearchRecursion(int array[], int low, int high, int target) {
    if (low > high) return -1; // kalo ga ketemu, print -1

    int mid = low + (high - low) / 2;
    // int mid = low + ((high - low) * (target - array[low]) / (array[high] - array[low]));

    if (array[mid] == target) return mid + 1;
    else if (array[mid] < target) return binarySearchRecursion(array, mid + 1, high, target); // kalo lokasinya masih di sebelah kiri dari target, geser ke kanan sampe ketemu target
    else if (target < array[mid]) return binarySearchRecursion(array, low, mid - 1, target); // kalo lokasinya masih di sebelah kanan dari target, geser ke kiri sampe ketemu target
}

int binarySearchLooping(int array[], int low, int high, int target) {
    while (low <= high) { // kalo masih belum ketemu, bakal looping terus
        int mid = low + (high - low) / 2;
        // int mid = low + ((high - low) * (target - array[low]) / (array[high] - array[low]));

        if (array[mid] == target) return mid + 1; // kalo udah ketemu, lansung berhenti
        else if (array[mid] < target) low = mid + 1; // geser ke kanan
        else if (target < array[mid]) high = mid - 1; // geser ke kiri
    }
    return -1; // kalo keluar looping (ga ketemu), print -1
}

// print binary search
void printBinarySearch(int array[], int low, int high, int target) {
    printf("Lokasi angka menggunakan binary search recursion : %d\n", binarySearchRecursion(array, low, high, target));

    printf("Lokasi angka menggunakan binary search looping : %d\n", binarySearchLooping(array, low, high, target));
}

// print sebelum sort
void print(int array[], int n) {
    printf("Array sebelum di sort : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {5, 9, -1, -10, 3, 6, 98, 8, 0, 2};
    int n = sizeof(array) / sizeof(array[0]);

    print(array, n);
    printBubbleSort(array, n);
    printQuickSort(array, 0, n - 1, n);
    printMergeSort(array, 0, n - 1, n);
    
    int target = 0;
    printf("Input angka yang ingin dicari lokasinya setelah di sorting : ");
    scanf("%d", &target);

    printBinarySearch(array, 0, n - 1, target);
    return 0;
}