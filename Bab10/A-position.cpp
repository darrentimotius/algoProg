#include <stdio.h>

int binarySearch(int A[], int low, int high, int target){
    if (low > high) return -1;
    int mid = low + (high - low)/2;

    if (A[mid] == target) return mid+1;
    else if (A[mid] < target) return binarySearch(A, mid + 1, high, target);
    else if (A[mid] > target) return binarySearch(A, low, mid-1, target);
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
        printf("%d\n", binarySearch(array, 0, N - 1, temp));
    }
}