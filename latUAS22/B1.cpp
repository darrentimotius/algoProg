#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int flag = 0;
int partition(int arr[], int low, int high) {
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] == arr[high]) {
            flag = 1;
            break;
        } else if (arr[j] < arr[high]) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void sort(int arr[], int low, int high) {
    if (low >= high) return;

    int p = partition(arr, low, high);
    sort(arr, low, p - 1);
    sort(arr, p + 1, high);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, 0, n - 1);

    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    if (flag) {
        puts("Terdapat Duplikat");
    }
    flag = 0;
    return 0;
}