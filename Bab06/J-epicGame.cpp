#include <stdio.h>

int counter = 0;

void game(long long int N) {
    if (N == 1) return;
    else if (N % 2 == 0) {
        counter++;
        game(N / 2);
    } else if (N % 2 == 1) {
        counter++;
        game(N * 3 + 1);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        long long int N;
        scanf("%lld", &N);

        game(N);

        printf("Case #%d: ", tc);
        if (counter % 2 == 0) printf("Lili\n");
        else printf("Jojo\n");

        counter = 0;
    }
}