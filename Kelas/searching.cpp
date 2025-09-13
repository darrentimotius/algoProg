#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int n, int find) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == find) return i;
    }
    return -1;
}

int binarySearch(int arr[], int l, int h, int find) {
    if (l > h) return -1;
    int m = (l + h) / 2;
    if (arr[m] == find) return m;
    else if (find < arr[m]) return binarySearch(arr, l, m - 1, find);
    else return binarySearch(arr, m + 1, h, find);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[105];
    for (int i = 0; i < 100; i++) {
        arr[i] = rand() % 100 + 1;
    }

    bubble(arr, 100);

    int q, a;
    scanf("%d", &q);
    
    for (int i = 0; i < q; i++) {
        scanf("%d", &a);
        // int idx = linearSearch(arr, 100, a);
        int idx = binarySearch(arr, 0, 99, a);
        if (idx >= 0) printf("Ketemu %d\n", idx + 1);
        else puts("Tidak Ketemu");
    }
    return 0;
}