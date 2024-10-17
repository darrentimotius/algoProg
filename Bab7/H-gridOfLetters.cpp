#include <stdio.h>
#include <string.h>

int main() {
    int R, C;
    scanf("%d %d", &R, &C); getchar();

    char array[205][205];
    for (int i = 0; i < R; i++) {
        char temp[205];
        scanf("%s", temp); getchar();

        for (int j = 0; j < C; j++) {
            for (int k = 0; k < C - 1; k++) {
                if (temp[k] > temp[k+1]) {
                    char tempSort = temp[k];
                    temp[k] = temp[k+1];
                    temp[k+1] = tempSort;
                }
            }
        }
        strcpy(array[i], temp);
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < R - 1; j++) {
            if (strcmp(array[j], array[j+1]) > 0) {
                char tempString[205];
                strcpy(tempString, array[j]);
                strcpy(array[j], array[j+1]);
                strcpy(array[j+1], tempString);
            }
        }
    }

    for (int i = R - 1; i >= 0; i--) {
        printf("%s\n", array[i]);
    }
    return 0;
}