#include <stdio.h>

int binarySearch(long long int sumA[], int low, int high, long long int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (target >= sumA[high]) return high + 1;
        if (target < sumA[low]) return -1;
        if (high - low == 1) return low + 1;
        if (target == sumA[mid]) return mid + 1;
        
        if (target < sumA[mid]) high = mid;
        else if (target > sumA[mid]) low = mid;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    long long int array[100005];
    long long int sum = 0;
    long long int sumArray[100005] = {0};
    for (int i = 0; i < N; i++) {
        scanf("%lld", &array[i]);
        sum += array[i];
        sumArray[i] = sum;
    }

    int Q;
    scanf("%d", &Q);

    for (int tc = 1; tc <= Q; tc++) {
        long long int M;
        scanf("%lld", &M);
        printf("Case #%d: %d\n", tc, binarySearch(sumArray, 0, N - 1, M));
    }
    return 0;
}