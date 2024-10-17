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
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int ke1[6], ke2[6], ke3[6], ke4[6], ke5[6];
        for (int i = 0; i < 5; i++) {
            scanf("%d", &ke1[i]);
        }
        for (int i = 0; i < 5; i++) {
            scanf("%d", &ke2[i]);
        }
        for (int i = 0; i < 5; i++) {
            scanf("%d", &ke3[i]);
        }
        for (int i = 0; i < 5; i++) {
            scanf("%d", &ke4[i]);
        }
        for (int i = 0; i < 5; i++) {
            scanf("%d", &ke5[i]);
        }

        quickSort(ke1, 0, 4); quickSort(ke2, 0, 4); quickSort(ke3, 0, 4); quickSort(ke4, 0, 4); quickSort(ke5, 0, 4);

        for (int i = 0; i < 5; i++) {
            
        }
    }
    return 0;
}