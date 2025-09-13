#include <stdio.h>

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    int s;
    scanf("%d", &s);

    int n;
    scanf("%d", &n);

    int a[105];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, n);

    int count = 0;
    for (int i = 0; i < n; i++) {
        s -= a[i];
        if (s > 0 && a[i] > 0) count++;
    }

    printf("%d\n", count);

    return 0;
}