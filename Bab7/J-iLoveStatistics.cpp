#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);

        int array[5005];
        double total = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &array[i]);
            total += array[i];
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - 1; j++) {
                if (array[j] > array[j+1]) {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }

        double median = 0;
        if (N % 2 == 0) {
            median = (array[N/2] + array[N/2-1]) * 0.5;
        } else median = array[N/2];

        double mean = total / N;
        printf("Case #%d:\n", tc);
        printf("Mean : %.2lf\nMedian : %.2lf\n", mean, median);
    }
    return 0;
}