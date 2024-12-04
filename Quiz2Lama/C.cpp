#include <stdio.h>
#include <string.h>

void swap (char a[], char b[]) {
    char t[105];
    strcpy(t, a);
    strcpy(a, b);
    strcpy(b, t);
}

int partition(char a[][105], int l, int h) {
    int i = l - 1;
    for (int j = l; j < h; j++) {
        if (strcmp(a[j], a[h]) < 0) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[h]);
    return i + 1;
}

void quick(char a[][105], int l, int h) {
    if (l >= h) return;
    int p = partition(a, l, h);
    quick(a, l + 1, h);
    quick(a, l, h - 1);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) return 0;

    char a[10005][105];
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }

    quick(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%s\n", a[i]);
    }

    return 0;
}