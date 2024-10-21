#include <stdio.h>

void swap (long long int *a, long long int *b) {
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

long long int partition(long long int A[], int low, int high) {
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

void quickSort(long long int A[], int low, int high) {
    if (low < high) {
        int pivot = partition(A, low, high);
        quickSort(A, low, pivot - 1);
        quickSort(A, pivot + 1, high);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    long long int array[105];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &array[i]);
    }

    quickSort(array, 0, N - 1);

    long long int power;
    scanf("%lld", &power);

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] <= power) {
            count++;
            power -= array[i];
        }
    }

    printf("%d\n", count);
    return 0;
}