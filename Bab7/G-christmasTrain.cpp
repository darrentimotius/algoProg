#include <stdio.h>

int count = 0;

int abs(int x) {
    if (x < 0) return -x;
    return x;
}

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
        count++;
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N, X;
        scanf("%d %d", &N, &X);

        int array[505];
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }

        // quickSort(array, 0, N - 1);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - 1; j++) {
                if (array[j] > array[j+1]) {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                    count++;
                }
            }
        }

        printf("Case #%d: %d\n", tc, count * X);

        count = 0;
    }
}