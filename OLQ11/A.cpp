#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int search(char arr[][25], int n, char temp[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i], temp) == 0) return i;
    }
    return -1;
}

int main() {
    FILE *f = fopen("testdata.in", "r");

    int n;
    fscanf(f, "%d\n", &n);

    char arr[105][25];
    for (int i = 0; i < n; i++) {
        fscanf(f, "%s\n", arr[i]);
    }

    int t;
    fscanf(f, "%d\n", &t);
    for (int tc = 1; tc <= t; tc++) {
        char temp[25];
        fscanf(f, "%s\n", temp);

        printf("%d\n", search(arr, n, temp));
    }

    return 0;
}