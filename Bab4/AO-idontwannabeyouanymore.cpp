#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N); getchar();

        char S[N+1];
        scanf("%[^\n]", S); getchar();

        printf("Case #%d: ", i);
        for (int j = 0; j < N; j++) {
            if (S[j] >= 'a' && S[j] <= 'z') printf("%c", S[j]);
        }
        printf("\n");
    }
}

/*
3
18
november 22nd 1919
36
n$e ve#- rg%&on$ n#ag i've y*o u"up
28

*/