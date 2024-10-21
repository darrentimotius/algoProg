#include <stdio.h>

int binarySearch(int A[], int low, int high, int target){
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (A[mid] == target) {
            for (int i = low; i <= mid; i++) {
                if (A[i] == target) return i;
            }
        }
        if (A[mid] > target) return binarySearch(A, low, mid - 1, target);
        return binarySearch(A, mid + 1, high, target);
    }
    return -2;

    // while (low <= high) {
    //     int mid = low + (high - low) / 2;
    //     if (A[mid] == target) {
    //         for (int i = low; i <= mid; i++) {
    //             if (A[i] == target) return i;
    //         }
    //     }
    //     if (A[mid] < target) low = mid + 1;
    //     else high = mid - 1;
    // }
    return -2;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int array[100005];
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < M; i++) {
        int temp;
        scanf("%d", &temp);
        printf("%d\n", binarySearch(array, 0, N - 1, temp) + 1);
    }
}