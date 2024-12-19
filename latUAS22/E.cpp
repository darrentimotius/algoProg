#include<stdio.h>

void mapping(char map[][1000], int x, int y, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (map[x][y] == '#') return;

    map[x][y] = '#';
    mapping(map, x + 1, y, n, m);
    mapping(map, x - 1, y, n, m);
    mapping(map, x, y + 1, n, m);
    mapping(map, x, y - 1, n, m);
}

int main() {
    FILE *f = fopen("testdata.in", "r");
    int n, m, p;
    fscanf(f, "%d %d %d\n", &n, &m, &p);

    char map[1000][1000];
    for (int i = 0; i < n; i++) {
        fscanf(f, "%s\n", map[i]);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '-') {
                mapping(map, i, j, n, m);
                count++;
            }
        }
    }
    printf("%d\n", count * p);
    return 0;
}