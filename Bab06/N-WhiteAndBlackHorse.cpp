#include <stdio.h>

// board = 8 x 8
// 8 | | | | | | |#
// 7 | | | | |#| | 
// 6 | | | | | | |#
// 5 | | | | |x| | 
// 4 | | | | | | | 
// 3 | | | |*| | | 
// 2 | |*| | | | | 
// 1*| | | | | | | 
//  a b c d e f g h

    int flag = 0;
    void catur(int count, int N, char X1, int Y1, char X2, int Y2) {
        if (flag) return;
        if ('H' < X1 || X1 < 'A' || 8 < Y1 || Y1 < 1) return;
        if (X1 == X2 && Y1 == Y2) {
            flag = 1;
            return;
        }
        if (count == N) {
            return;
        }

        // semua kemungkinan pergerakan kuda
        catur(count+1, N, X1+2, Y1+1, X2, Y2);
        catur(count+1, N, X1+1, Y1+2, X2, Y2);

        catur(count+1, N, X1+2, Y1-1, X2, Y2);
        catur(count+1, N, X1+1, Y1-2, X2, Y2);

        catur(count+1, N, X1-1, Y1-2, X2, Y2);
        catur(count+1, N, X1-2, Y1-1, X2, Y2);

        catur(count+1, N, X1-2, Y1+1, X2, Y2);
        catur(count+1, N, X1-1, Y1+2, X2, Y2);
    }

    int main() {
        int T;
        scanf("%d", &T); getchar();

        for (int tc = 1; tc <= T; tc++) {
            int N;
            scanf("%d", &N); getchar();
            // kali 2 soalnya pergerakannya untuk 2 kuda
            N *= 2;
            
            char X1, X2;
            int Y1, Y2;
            scanf("%c%d %c%d", &X1, &Y1, &X2, &Y2); getchar();
            // ubah sumbu x jadi angka soalnya pas pake huruf error trus
            // int X1 = temp1 - 'A' + 1;
            // int X2 = temp2 - 'A' + 1;
            
            // printf("%d%d %d%d\n", X1, Y1, X2, Y2);
            // printf("%c%d %c%d\n", X1, Y1, X2, Y2);
            catur(0, N, X1, Y1, X2, Y2);
            
            printf("Case #%d: ", tc);
            if (flag) puts("YES");
            else puts("NO");

            flag = 0;
        }
        return 0;
    }