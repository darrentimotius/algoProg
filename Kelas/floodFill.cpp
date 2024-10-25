#include <stdio.h>

char map[10][11] {
    "##########",
    "#        #",
    "#        #",
    "#        #",
    "#        #",
    "#        #",
    "#        #",
    "#        #",
    "#        #",
    "##########"
};

void printMap() {
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%s\n", map[i]);
    }
    printf("\n");
}

void floodFill(int x, int y) {
    if (map[x][y] == '#' || map[x][y] == '.') return;
    else if (map[x][y] == ' ') {
        map[x][y] = '.';
        printMap();
    }

    floodFill(x+1, y);
    floodFill(x-1, y);
    floodFill(x, y+1);
    floodFill(x, y-1);
}

int main() {
    printMap();
    floodFill(1, 1);
    printMap();
    return 0;
}