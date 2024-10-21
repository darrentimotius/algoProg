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
        int N;
        scanf("%d", &N);

        int mmr[1005];
        for (int i = 0; i < N; i++) {
            scanf("%d", &mmr[i]);
        }

        quickSort(mmr, 0, N - 1);

        int search;
        scanf("%d", &search);
        
        // cek apakah search ada di list mmr ga sama dia terbesar ato bukan
        int index = 0;
        int hasilSearch1 = -1;
        int flagHighest = 0;
        for (int i = 0; i < N; i++) {
            if (mmr[i] == search) {
                hasilSearch1 = search;
                index = i;
                if (i == N - 1) {
                    flagHighest = 1;
                    mmr[i] = -1;
                }
                
            }
        }

        int hasilSearch2 = -1;
        // kalo dia tertinggi
        if (flagHighest) hasilSearch2 = mmr[N - 2];

        // kalo dia bukan tertinggi
        if (!flagHighest && hasilSearch1 != -1) {
            hasilSearch2 = mmr[index+1];
            // for (int i = 0; i < N; i++) {
            //     if (mmr[i] < hasilSearch2) hasilSearch2 = mmr[i];
            // }
        }

        printf("CASE #%d: ", tc);
        if (hasilSearch1 > hasilSearch2) printf("%d %d\n", hasilSearch2, hasilSearch1);
        else printf("%d %d\n", hasilSearch1, hasilSearch2);
    }
    return 0;
}