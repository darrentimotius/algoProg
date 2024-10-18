#include <stdio.h>

int N, M;
int count = 0;
void check(int X, int Y, char S[105][105]) {
    if (X < 0 || Y < 0 || X >= N || Y >= M || S[X][Y] == '#') return;

    if (S[X][Y] == '*') count++;
    
    S[X][Y] = '#';

    // gerak ke atas, bawah, kiri, kanan
    check(X+1, Y, S);
    check(X-1, Y, S);
    check(X, Y+1, S);
    check(X, Y-1, S);
}

int main() {
    int T;
    scanf("%d", &T); getchar();

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d", &N, &M); getchar();

        char S[105][105];
        int X, Y;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%c", &S[i][j]);
                if (S[i][j] == 'P') {
                    X = i;
                    Y = j;
                }
            }
            getchar();
        }

        check(X, Y, S);
        printf("Case #%d: ", tc);
        printf("%d\n", count);
        count = 0;
    }
    return 0;
}