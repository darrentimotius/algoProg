#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n + 5], flag[n + 5];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        flag[i] = 0;
    }

    for (int c = 0; c < n;) {
        int max = -10, maxIdx = -1;
        for (int i = 0; i < n; i++) {
            if (flag[i] == 0 && arr[i] > max) {
                max = arr[i];
                maxIdx = i;
            }
        }

        if (maxIdx != -1) {
            printf("%d", max);
            flag[maxIdx] = 1;
            c++;
        }

        int minVal = 99999, minIdx = -1;
        for (int i = 0; i < n; i++) {
            if (flag[i] == 0 && arr[i] < minVal) {
                minVal = arr[i];
                minIdx = i;
            }
        }

        if (minIdx != -1) {
            printf("%d", arr[minIdx]);
            flag[minIdx] = 1;
            c++;
        }
        if (c == n - 1) printf("\n");
        else printf(" ");
    }
    return 0;
}