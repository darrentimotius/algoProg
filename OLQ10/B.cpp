#include <stdio.h>
#include <string.h>

int binarySearch(char arr[][105], int l, int h, char target[]) {
    if (l > h) return 0;
    int m = l + (h - l) / 2;

    if (strcmp(arr[m], target) == 0) return m + 1;
    else if (strcmp(target, arr[m]) > 0) return binarySearch(arr, m + 1, h, target);
    else return binarySearch(arr, l, m - 1, target);
}

int main() {
    int n;
    scanf("%d", &n);

    int p;
    scanf("%d", &p);

    char arr[105][105];
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    char target[105];
    scanf("%s", target);

    int locAwal = binarySearch(arr, 0, n - 1, target);

    if (locAwal == 0) {
        printf("%d\n", locAwal);
        return 0;
    }

    int loc = 0;
    if (locAwal % p == 0) loc = locAwal / p;
    else loc = locAwal / p + 1;

    printf("%d\n", loc);
    return 0;
}