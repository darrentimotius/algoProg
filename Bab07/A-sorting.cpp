#include <stdio.h>

long long int abs(long long int x) {
    if (x < 0) return -x;
    return x;
}

void swap (long long int *a, long long int *b) {
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(long long int A[], long long int low, long long int high) { // return pivot index
    long long int i = low - 1;// index elemen terkecil
    for (int j = low; j < high; j++) { // j adalah index elemen yang sedang di cek
        if (A[j] <= A[high]) { // jika elemen ke j lebih kecil dari elemen terakhir
            i++; // index elemen terkecil bertambah
            swap(&A[i], &A[j]); // tukar elemen ke i dengan elemen ke j
        }
    }
    swap(&A[i+1], &A[high]); // tukar elemen ke i+1 dengan elemen terakhir // elemen terakhir menjadi pivot
    return i + 1; // return index pivot
}

void quickSort(long long int A[], long long int low, long long int high) { // low index elemen terkecil, high index elemen terbesar
    if (low < high) { // jika low lebih kecil dari high
        int pivot = partition(A, low, high); // pivot adalah index elemen terakhir
        quickSort(A, low, pivot - 1); // rekursif quicksort untuk elemen sebelum pivot
        quickSort(A, pivot + 1, high); // rekursif quicksort untuk elemen setelah pivot
    }
}

int main() {
    int N;
    scanf("%d", &N);

    long long int A[100005];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    // bubble sort
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N - 1; j++) {
    //         if (A[j] > A[j+1]) {
    //             long long int temp = A[j];
    //             A[j] = A[j+1];
    //             A[j+1] = temp;
    //         }
    //     }
    // }

    // for (int i = 0; i < N; i++) {
    //     printf("%lld", A[i]);
    // }

    quickSort(A, 0, N - 1);

    long long int max = -10000005;
    long long int diff[100005] = {0};
    for (int i = 0; i < N - 1; i++) {
        diff[i] = abs(A[i] - A[i+1]);
        if (diff[i] > max) max = diff[i];
    }

    int flag = 0;
    for (int i = 0; i < N - 1; i++) {
        if (diff[i] == max) {
            if (flag) printf(" ");
            printf("%lld %lld", A[i], A[i+1]);
            flag = 1;
        }
    }
    printf("\n");

    return 0;
}