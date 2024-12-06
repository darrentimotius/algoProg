/*
Counting Islands

On a map with size s * s.
Given n query. draw a rectangle from (x1, y1) to (x2, y2) for each query.
Find the number of islands on the map after each query.

Format Input:
first line contains two integers s and n (1 <= s <= 1000, 1 <= n <= 100000)
next n lines contain four integers x1, y1, x2, y2 (1 <= x1 <= x2 <= s, 1 <= y1 <= y2 <= s)

Format Output:
draw the map after each query. "#" is water, "." is land.
last line contains the number of islands on the map.
*/

#include <stdio.h>
#define gc getchar();

void floodFill(char map[1005][1005], int s, int x, int y) {
    if (x < 1 || x > s || y < 1 || y > s || map[x][y] == '#') return;

    map[x][y] = '#';

    floodFill(map, s, x+1, y);
    floodFill(map, s, x-1, y);
    floodFill(map, s, x, y+1);
    floodFill(map, s, x, y-1);
}

int main(){
    int S, N, x1, y1, x2, y2;
    scanf("%d %d", &S, &N); gc

    char map[1005][1005];
    for (int i = 1 ; i <= S ; i++){
        for (int j = 1 ; j <= S ; j++){
            map[i][j] = '#';
        }
    }

    for (int i = 0 ; i < N ; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2); getchar();
        for (int j = x1 ; j <= x2 ; j++){
            for (int k = y1 ; k <= y2 ; k++){
                map [j][k] = '.';
            }
        }
    }

    for (int i = 1 ; i <= S ; i++){
        for (int j = 0 ; j <= S; j++){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    int count = 0;
    for (int i = 1 ; i <= S ; i++){
        for (int j = 1 ; j <= S ; j++){
            if (map[i][j] == '.'){
                floodFill(map, S, i, j);
                count++;
            }
        }
    }
    printf("%d\n", count);

    return 0;
}