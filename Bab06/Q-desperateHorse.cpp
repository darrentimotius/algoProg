#include <stdio.h>

int minCount = 8;
void catur(int count, char X1, int Y1, char X2, int Y2) {
    if (count > minCount) return; 
    if ('H' < X1 || X1 < 'A' || 8 < Y1 || Y1 < 1) return;
    if (X1 == X2 && Y1 == Y2) {
        if (count < minCount) minCount = count;
        return;
    }

    catur(count+1, X1+2, Y1+1, X2, Y2);
    catur(count+1, X1+1, Y1+2, X2, Y2);

    catur(count+1, X1+2, Y1-1, X2, Y2);
    catur(count+1, X1+1, Y1-2, X2, Y2);

    catur(count+1, X1-1, Y1-2, X2, Y2);
    catur(count+1, X1-2, Y1-1, X2, Y2);

    catur(count+1, X1-2, Y1+1, X2, Y2);
    catur(count+1, X1-1, Y1+2, X2, Y2);
}

int main() {
    int T;
    scanf("%d", &T); getchar();

    for (int tc = 1; tc <= T; tc++) {
        minCount = 8;

        char X1, X2;
        int Y1, Y2;
        scanf("%c%d %c%d", &X1, &Y1, &X2, &Y2); getchar();

        catur(0, X1, Y1, X2, Y2);

        printf("Case #%d: ", tc);
        printf("%d\n", minCount);

    }
    return 0;
}