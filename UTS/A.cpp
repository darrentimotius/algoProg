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