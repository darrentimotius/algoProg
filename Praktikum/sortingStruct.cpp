#include <stdio.h>
#include <string.h>

struct Mahasiswa {
    char nama[25];
    int nilai;
};

void printStruct(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", mhs[i].nama, mhs[i].nilai);
    }
}

void swap(Mahasiswa *a, Mahasiswa *b) {
    Mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            // cek nilai
            if (mhs[j].nilai < mhs[j+1].nilai) {
                swap(&mhs[j], &mhs[j+1]);
            } else if (mhs[j].nilai == mhs[j+1].nilai) {
                if (strcmp(mhs[j].nama, mhs[j+1].nama) > 0) {
                    swap(&mhs[j], &mhs[j+1]);
                }
            }
        } 
    }
}

int main() {
    int n;
    scanf("%d", &n); getchar();

    Mahasiswa mhs[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %d", mhs[i].nama, &mhs[i].nilai);
    }

    puts("Sesudah sorting :");
    bubbleSort(mhs, n);
    printStruct(mhs, n);

}