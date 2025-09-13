#include <stdio.h>

char map[11][11];
int max = 100, flag = 0;

void mapping(int x1, int y1, int x2, int y2, int count) {
    if (flag) return;
    if (x1 > 9 || x1 < 0 || y1 > 9 || y1 < 0) return;
    if (map[x1][y1] == '#') return;
    if (map[x1][y1] == 'E') {
        if (count < max) max = count;
        flag = 1;
        return;
    }

    map[x1][y1] = '#';

    mapping(x1 + 1, y1, x2, y2, count + 1);
    mapping(x1 - 1, y1, x2, y2, count + 1);
    mapping(x1, y1 + 1, x2, y2, count + 1);
    mapping(x1, y1 - 1, x2, y2, count + 1);
}

int main() {
    FILE *f = fopen("testdata.in", "r");

    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fscanf(f, "%c", &map[i][j]);
            if (map[i][j] == 'S') {
                x1 = i;
                y1 = j;
            }
            if (map[i][j] == 'E') {
                x2 = i;
                y2 = j;
            }
        }
        fscanf(f, "\n");
    }
    // printf("%d %d %d %d\n", x1, y1, x2, y2);
    mapping(x1, y1, x2, y2, 0);

    // for (int i = 0; i < 10; i++) printf("%s\n", map[i]);

    printf("%d\n", max);


    return 0;
}