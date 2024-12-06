#include <stdio.h>

int move[10][3] = {
    {1, 2},
    {2, 1},
    {2, -1},
    {1, -2},
    {-1, -2},
    {-2, -1},
    {-2, 1},
    {-1, 2}
};

char path[100][5];
int nPath = 0;

int backtracking(int board[10][10], int n, int m, int x, int y, int step) {
    if (step == n * m) return 1;

    for (int i = 0; i < 8; i++) {
        int nextX = x + move[i][0];
        int nextY = y + move[i][1];

        if (0 <= nextX && nextX < n && 0 <= nextY && nextY < m && board[nextX][nextY] < m && board[nextX][nextY] == -1) {
            board[nextX][nextY] = step;
            path[nPath][0] = nextX + 'A';
            path[nPath][1] = nextY + '1';
            path[nPath][2] = '\0';
            nPath++;

            if (backtracking(board, n, m, nextX, nextY, step + 1)) return 1;

            board[nextX][nextY] = -1;
            nPath--;
        }

    }
}

int main() {
    int n, m;
    char pos[5];
    scanf("%d %d %s", &n, &m, pos);

    int board[10][10];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = -1;
        }
    }

    int x = pos[0] - 'A', y = pos[1] - '1';
    board[x][y] = 0;
    path[nPath][0] = x + 'A';
    path[nPath][1] = y + '1';
    path[nPath][2] = '\0';
    nPath++;

    if (backtracking(board, n, m, x, y, 1)) {
        puts("Yes");
        printf("%s", path[0]);

        for (int i = 1; i < nPath; i++) {
            printf("-%s", path[i]);
        }
        printf("\n");

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%2d ", board[i][j]);
            }
            printf("\n");
        }
    }
    else puts("No");

    return 0;
}