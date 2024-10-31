#include <stdio.h>

long long int tempMax;
int search (int array[], int length, long long max) {
    int maxLength = 0, index = 0, decrease = 0, temp = 0;
    tempMax = max;

    while (index < length) {
        if (array[index] > max) {
            temp = 0;
            tempMax = max;
            index++;
            continue;
        } else if (tempMax >= array[index]) {
            tempMax -= array[index];
            temp++;
            index++;
        } else if (array[index] > tempMax && array[index] <= max) {
            tempMax += array[decrease];
            decrease++;
            temp--;
        }
        if (temp > maxLength) maxLength = temp;

    }
    if (maxLength == 0) maxLength = -1;
    return maxLength;
}

int main() {
    int N;
    scanf("%d", &N);

    int array[5005];
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        long long int M;
        scanf("%lld", &M);

        printf("Case #%d: %d\n", tc, search(array, N, M));
    }
    return 0;
}