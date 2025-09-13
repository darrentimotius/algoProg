#include <stdio.h>

int lokasi = -1;
void mapping(int arr[][1000], int x2, int y2, int n, int m) {
    if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) return;
    if (arr[x2][y2] > lokasi) return;

    // berhasil isi air
    lokasi = arr[x2][y2];
    arr[x2][y2] = 9999;

    mapping(arr, x2 + 1, y2, n, m);
    mapping(arr, x2 - 1, y2, n, m);
    mapping(arr, x2, y2 + 1, n, m);
    mapping(arr, x2, y2 - 1, n, m);
}

int main() {
    FILE *f = fopen("testdata.in", "r");
    int n, m;
    fscanf(f, "%d %d\n", &n, &m);

    // scan map
    int arr[1000][1000];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(f, "%d", &arr[i][j]);
        }
        fscanf(f, "\n");
    }

    // scan sumber air
    int x = 0, y = 0;
    fscanf(f, "%d %d\n", &y, &x);
    lokasi = arr[x][y];
    // printf("%d %d\n", x, y);
    mapping(arr, x, y, n, m);

    // print map
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != 9999) printf(".");
            else printf("W");
            if (j != m - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}