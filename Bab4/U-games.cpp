#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);
        getchar();

        char S[N+1];
        scanf("%s", S);
        getchar();

        int B = 0, L = 0, T = 0;

        for (int j = 0; j < N; j++) {
            if (S[j] == 'B') B++;
            else if (S[j] == 'L') L++;
            else T++;
        }
        if ((T >= B) && (T >= L)) printf("None\n");
        else if ((B > L) && (B > T)) printf("Bibi\n");
        else if ((L > B) && (L > T)) printf("Lili\n");
        else printf("None\n");
    }
    return 0;
}