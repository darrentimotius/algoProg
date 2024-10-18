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

int main() {
    int N;
    scanf("%d", &N);

    int array[100005];
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    quickSort(array, 0, N - 1);

    for (int i = (N / 2) + 1; i < N; i++) {
        printf("%d", array[i]);
        if (i != N - 1) printf(" ");
    }
    printf("\n");
    return 0;
}