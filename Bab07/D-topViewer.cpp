#include <stdio.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapString(char a[], char b[]) {
    char temp[1005] = "";
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int partition(int A[], char B[][1005], char C[][1005], int low, int high) {
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (A[j] <= A[high]) {
            i++;
            swap(&A[i], &A[j]);
            swapString(B[i], B[j]);
            swapString(C[i], C[j]);
        }
    }
    swap(&A[i+1], &A[high]);
    swapString(B[i+1], B[high]);
    swapString(C[i+1], C[high]);
    return i + 1;
}

void quickSort(int A[], char B[][1005], char C[][1005], int low, int high) {
    if (low < high) {
        int pivot = partition(A, B, C, low, high);
        quickSort(A, B, C, low, pivot - 1);
        quickSort(A, B, C, pivot + 1, high);
    }
}

int main() {
    FILE *file;
    file = fopen("testdata.in", "r");

    char judul[105][1005], artis[105][1005];
    int view[105];
    int count = 0;
    
    while(!feof(file)) {
        fscanf(file, "%[^#]#%[^#]#%d\n", judul[count], artis[count], &view[count]);
        count++;
    }

    quickSort(view, judul, artis, 0, count - 1);

    for (int i = count - 1; i >= 0; i--) {
        printf("%s by %s - %d\n", judul[i], artis[i], view[i]);
    }
    fclose(file);
    return 0;
}