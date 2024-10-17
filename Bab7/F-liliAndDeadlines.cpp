#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapString(char a[], char b[]) {
    char temp[15] = "";
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int partition(int A[], char B[][15], int low, int high) {
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (A[j] <= A[high]) {
            i++;
            swap(&A[i], &A[j]);
            swapString(B[i], B[j]);
        }
    }
    swap(&A[i+1], &A[high]);
    swapString(B[i+1], B[high]);
    return i + 1;
}

void quickSort(int A[], char B[][15], int low, int high) {
    if (low < high) {
        int pivot = partition(A, B, low, high);
        quickSort(A, B, low, pivot - 1);
        quickSort(A, B, pivot + 1, high);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    char nama[105][15];
    int time[105];
    for (int i = 0; i < N; i++) {
        scanf("%s %d", nama[i], &time[i]);
    }

    quickSort(time, nama, 0, N - 1);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (time[j] == time[j+1]) {
                if (strcmp(nama[j], nama[j+1]) > 0) {
                    char temp[15];
                    strcpy(temp, nama[j]);
                    strcpy(nama[j], nama[j+1]);
                    strcpy(nama[j+1], temp);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%s\n", nama[i]);
    }
    return 0;
}