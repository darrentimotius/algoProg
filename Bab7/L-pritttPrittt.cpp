#include <stdio.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int low, int high) {
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (A[j] <= A[high]) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i+1], &A[high]);
    return i + 1;
}

void quickSort(int A[], int low, int high) {
    if (low < high) {
        int pivot = partition(A, low, high);
        quickSort(A, low, pivot - 1);
        quickSort(A, pivot + 1, high);
    }
}

int binarySearch(int A[], int low, int high, int target){
    if (low > high) return -1;
    int mid = low + (high - low)/2;

    if (A[mid] == target) return mid+1;
    else if (A[mid] < target) return binarySearch(A, mid + 1, high, target);
    else if (A[mid] > target) return binarySearch(A, low, mid-1, target);
}

int main() {
    int N;
    scanf("%d", &N);

    int array[100005];
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    quickSort(array, 0, N - 1);

    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int temp;
        scanf("%d", &temp);
        printf("%d\n", binarySearch(array, 0, N - 1, temp));
    }
    return 0;
}