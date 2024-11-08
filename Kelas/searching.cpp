#include <stdio.h>

// Linear Search
int linearSearch (int arr[], int target, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// Binary Search
int iterativeBinary (int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        if (arr[mid] > target) high = mid - 1;
    }
    return -1;
}

int recursionBinary (int arr[], int low, int high, int target) {
    if (low <= high) {
        // int mid = low + (high - low) / 2;
        int mid = low + ((high - low) * (target - arr[low]) / (arr[high] - arr[low]));

        if (arr[mid] == target) return mid;
        if (arr[mid] < target) return recursionBinary(arr, mid + 1, high, target);
        else return recursionBinary(arr, low, mid - 1, target);
    }
    return -1;
}

int main() {
    // int arr[] = {3, 4, 10, 9, 5};
    int arr[] = {4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    // int result = linearSearch(arr, 10, size);
    int result = iterativeBinary(arr, 0, size - 1, 8);
    printf("%d\n", result);

    int result1 = recursionBinary(arr, 0, size - 1, 8);
    printf("%d\n", result1);
    return 0;
}