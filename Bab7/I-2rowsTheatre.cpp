#include <stdio.h>

int swap(int *a, int *b) {
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
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);

        int array[505];
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }

        quickSort(array, 0, N - 1);

        int gap = 0;
        for (int i = 0; i < N - 1; i++) {
            if (i == N / 2 - 1) continue;
            if (array[i+1] - array[i] > gap) gap = array[i+1] - array[i];
        }

        printf("Case #%d: %d\n", tc, gap);
    }
    return 0;
}