#include <stdio.h>

int binarySearch(int array[], int length, long long max) {
    int maxLength = 0;
    int index = 0;

    while (index < length) {
        long long temp = 0, temp2 = 0;
        for (int i = index; i < length; i++) {
            if (temp + array[i] <= max) {
                temp += array[i];
                temp2++;
            }
            else break;
        }
        if (temp2 > maxLength) maxLength = temp2;
        index++;
    }
    return maxLength;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        long long N, M;
        scanf("%lld %lld", &N, &M);

        int array[10005];
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
        }

        int search = binarySearch(array, N, M);
        if (search == 0) search = -1;

        printf("Case #%d: %d\n", tc, search);
    }
    return 0;
}