#include <stdio.h>

struct data {
    char warna[100];
    int count;
};

data dat[5] {
    {"Merah", 0},
    {"Hijau", 0},
    {"Biru", 0}
};

int count = 0;
void mapping(char arr[][1000], int x, int y, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (arr[x][y] == '+') return;

    count++;
    arr[x][y] = '+';
    mapping(arr, x + 1, y, n, m);
    mapping(arr, x - 1, y, n, m);
    mapping(arr, x, y + 1, n, m);
    mapping(arr, x, y - 1, n, m);
}

int main() {
    FILE *f = fopen("testdata.in", "r");
    int n, m;
    fscanf(f, "%d %d\n", &n, &m);

    char arr[1000][1000];
    for (int i = 0; i < n; i++) {
        fscanf(f, "%s\n", arr[i]);
    }

    // for (int i = 0; i < n; i++) {
    //     printf("%s\n", arr[i]);
    // }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'M' || arr[i][j] == 'H' || arr[i][j] == 'B') {
                char temp = arr[i][j];
                // printf("i = %d, j = %d\n", i, j);
                mapping(arr, i, j, n, m);
                // printf("%c = %d\n", arr[i][j], count);
                // arr[i][j] = '+';
                if (temp == 'M') dat[0].count += count;
                else if (temp == 'H') dat[1].count += count;
                else if (temp == 'B') dat[2].count += count;
                count = 0;
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     printf("%s\n", arr[i]);
    // }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 - i - 1; j++) {
            if (dat[j].count < dat[j+1].count) {
                data temp = dat[j];
                dat[j] = dat[j+1];
                dat[j+1] = temp;
            } else if (dat[j].count == dat[j+1].count) {
                if (dat[j].warna > dat[j+1].warna) {
                    data temp = dat[j];
                    dat[j] = dat[j+1];
                    dat[j+1] = temp;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        printf("%s : %d\n", dat[i].warna, dat[i].count);
    }

    return 0;
}