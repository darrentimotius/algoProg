#include <stdio.h>

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int A[], int low, int high) {
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

void quickSort (int A[], int low, int high) {
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
        int array[30];
        for (int i = 0; i < 25; i++) {
            scanf("%d", &array[i]);
        }

        quickSort(array, 0, 24);

        // for (int i = 0; i < 25; i++) {
        //     printf("%d ", array[i]);
        // }

        int a = array[0] / 2;
        int b = array[1] - a; 
        int c = array[3] - a;
        int e = array[24] / 2;
        int d = array[23] - e;

        printf("Case #%d: %d %d %d %d %d\n", tc, a, b, c, d, e);
    }
    return 0;
}

/*
1. dia nulis angkanya di kertas terus dijumlahin sama angka itu lagi
2. angka orang kedua dijumlahin sama angka pertama
3. lakuin terus sampe selesai
*/

/*
input  : 2 3 4 5 6 3 4 5 6 7 4 5 6 7 8 5 6 7 8 9 6 7 8 9 10
sorted : 2 3 3 4 4 4 5 5 5 5 6 6 6 6 6 7 7 7 7 8 8 8 9 9 10

input  : 3 3 4 4 2 2 3 3 3 2 3 2 3 3 2 2 2 3 2 2 3 3 4 4 3
sorted : 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 3 3 4 4 4 4

input  : 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4

input  : 5 7 6 7 10 8 2 3 4 11 11 3 4 5 6 8 9 7 8 9 4 6 7 8 12
sorted : 2 3 3 4 4 4 5 5 6 6 6 7 7 7 7 8 8 8 8 9 9 10 11 11 12
*/