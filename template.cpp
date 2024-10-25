#include <stdio.h>

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
int partition(int array[], int low, int high) {
    // melakukan sorting berdasarkan pivot
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] <= array[high]) {
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
    printf("\n\n");
}

// binary search
int binarySearchRecursion(int array[], int low, int high, int target) {
    if (low > high) return -1; // kalo ga ketemu, print -1

    int mid = low + (high - low) / 2;

    if (array[mid] == target) return mid + 1;
    else if (array[mid] < target) return binarySearchRecursion(array, mid + 1, high, target); // kalo lokasinya masih di sebelah kiri dari target, geser ke kanan sampe ketemu target
    else if (target < array[mid]) return binarySearchRecursion(array, low, mid - 1, target); // kalo lokasinya masih di sebelah kanan dari target, geser ke kiri sampe ketemu target
}

int binarySearchLooping(int array[], int low, int high, int target) {
    while (low <= high) { // kalo masih belum ketemu, bakal looping terus
        int mid = low + (high - low) / 2;

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
    int n = 10;

    print(array, n);
    printBubbleSort(array, n);
    printQuickSort(array, 0, n - 1, n);
    
    int target = 0;
    printf("Input angka yang ingin dicari lokasinya setelah di sorting : ");
    scanf("%d", &target);

    printBinarySearch(array, 0, n - 1, target);
    return 0;
}