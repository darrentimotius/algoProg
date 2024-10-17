#include <stdio.h>
#include <string.h>

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void swapChar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void swapString(char a[], char b[]) {
    char temp[1005] = "";
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int partition(double A[], char B[][1005], char C[], double D[], int low, int high) {
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (A[j] <= A[high]) {
            i++;
            swap(&A[i], &A[j]);
            swap(&D[i], &D[j]);
            swapString(B[i], B[j]);
            swapChar(&C[i], &C[j]);
        }
    }
    swap(&A[i+1], &A[high]);
    swap(&D[i+1], &D[high]);
    swapString(B[i+1], B[high]);
    swapChar(&C[i+1], &C[high]);
    return i + 1;
}

void quickSort(double A[], char B[][1005], char C[], double D[], int low, int high) {
    if (low < high) {
        int pivot = partition(A, B, C, D, low, high);
        quickSort(A, B, C, D, low, pivot - 1);
        quickSort(A, B, C, D, pivot + 1, high);
    }
}

int main() {
    FILE *file;
    file = fopen("testdata.in", "r");

    char kota[105][1005], satuan[105];
    double suhu[105];

    int index = 0;
    while(!feof(file)) {
        fscanf(file, "%[^#]#%lf#%c\n", kota[index], &suhu[index], &satuan[index]);
        index++;
    }

    double suhu2[105];
    for (int i = 0; i < index; i++) {
        if (satuan[i] == 'C') {
            suhu2[i] = suhu[i];
        } else {
            suhu2[i] = (suhu[i] - 32) * 5 / 9;
        }
    }

    quickSort(suhu2, kota, satuan, suhu, 0, index - 1);

    for (int i = 0; i < index; i++) {
        for (int j = 0; j < index - 1; j++) {
            if (suhu[j] == suhu[j+1]) {
                if (strcmp(kota[j], kota[j+1]) > 0) {
                    char temp[1005];
                    strcpy(temp, kota[j]);
                    strcpy(kota[j], kota[j+1]);
                    strcpy(kota[j+1], temp);
                }
            }
        }
    }

    for (int i = 0; i < index; i++) {
        printf("%s is %.2lf%c\n", kota[i], suhu[i], satuan[i]);
    }

    fclose(file);
    return 0;
}