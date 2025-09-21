/*
    DEFINE x, y
    SCAN x, y

    DEFINE n
    SCAN n

    DEFINE c
    SCAN c

    FOR i = 0 to n - 1
        IF c[i] == 'W'
            y = y + 1
        ELSE IF c[i] == 'S'
            IF y > 0 THEN
                y = y - 1
            END IF
        ELSE IF c[i] == 'D'
            x = x + 1
        ELSE IF c[i] == 'A'
            IF x > 0 THEN
                x = x - 1
            END IF
        END IF
    END FOR

    PRINT "Hov final coordinate is (x, y)."
*/

#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y); getchar();

    int n;
    scanf("%d", &n); getchar();

    char c[1005];
    scanf("%s", c);

    for (int i = 0; i < n; i++) {
        switch (c[i]) {
            case 'W':
                y++;
                break;
            case 'S':
                if (y > 0) y--;
                break;
            case 'D':
                x++;
                break;
            case 'A':
                if (x > 0) x--;
                break;
        }
    }

    printf("Hov final coordinate is (%d, %d).\n", x, y);
}