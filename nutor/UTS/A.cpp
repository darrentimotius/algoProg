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
    int X, Y, N;
    scanf("%d %d\n%d", &X, &Y, &N);

    char wasd[1005];
    scanf("%s", wasd);

    for (int i = 0; i < N; i++) {
        switch (wasd[i]) {
            case 'W':
                Y += 1;
                break;
            case 'A':
                if (X > 0) X -= 1;
                break;
            case 'S':
                if (Y > 0) Y -= 1;
                break;
            case 'D':
                X += 1;
                break;
        }
    }
    printf("Hov final coordinate is (%d, %d).\n", X, Y);
}