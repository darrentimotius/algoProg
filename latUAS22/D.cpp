#include <stdio.h>

int countTemp = 0;
void mapping(int map[][1000], int x1, int y1, int n) {
    if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n) return;
    if (!map[x1][y1]) return;
    countTemp++;

    map[x1][y1] = 0;
    mapping(map, x1 + 1, y1, n);
    mapping(map, x1 - 1, y1, n);
    mapping(map, x1, y1 + 1, n);
    mapping(map, x1, y1 - 1, n);
}

int main() {
    FILE *f = fopen("testdata.in", "r");
    int n;
    fscanf(f, "%d\n", &n);

    int map[1000][1000];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(f, "%d", &map[i][j]);
        }
        fscanf(f, "\n");
    }

    int x1 = 0, y1 = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j]) {
                mapping(map, i, j, n);
                if (max < countTemp) max = countTemp;
                countTemp = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", max);
    max = 0;

    // printf("x1 = %d, y1 = %d, x2 = %d, y2 = %d\n", x1, y1, x2, y2);

    return 0;
}