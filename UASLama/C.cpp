#include <stdio.h>

char map[105][105];
void fillMap(int x1, int y1, int x2, int y2, int n) {
    if (x1 < 1 || n < x1 || y1 < 1 || n < y1) return;
    if (x1 == x2 && y1 == y2) {
        map[y1][x1] = '*';
        return;
    }

    map[y1][x1] = '*'; // x = kolom, y = baris

    if (x1 < x2) fillMap(x1 + 1, y1, x2, y2, n); // right
    else if (x1 > x2) fillMap(x1 - 1, y1, x2, y2, n); // left
    
    if (y1 < y2)fillMap(x1, y1 + 1, x2, y2, n); // up
    else if (y1 > y2) fillMap(x1, y1 - 1, x2, y2, n); // down
}

int main() {
    FILE *f = fopen("testdata.in", "r");

    int n;
    fscanf(f, "%d\n", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            map[i][j] = '#';
        }
    }

    int pulau;
    fscanf(f, "%d\n", &pulau);

    for (int i = 0; i < pulau; i++) {
        int x1, y1, x2, y2; // x = kolom, y = baris
        fscanf(f, "%d %d %d %d\n", &x1, &y1, &x2, &y2);
        fillMap(x1, y1, x2, y2, n);
        // 2  1  2  2
        // x1 y1 x2 y2
    }

    char newMap[105][105];
    

    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= n; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*
10 *****#####
9  ######*###
8  #****#*#**
7  ######*###
6  ****##*#*#
5  ######*###
4  ##*#*#*###
3  ##*#*##*#*
2  #*##*##*#*
1  #*##*##*#*
   12345678910
*/