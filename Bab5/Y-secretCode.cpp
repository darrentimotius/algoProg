#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; ++t) {
        int Q;
        char S[1001];
        scanf("%d %s", &Q, S);

        for (int q = 0; q < Q; ++q) {
            int Li, Ri;
            scanf("%d %d", &Li, &Ri);
            Li--; // Convert to 0-based index
            Ri--; // Convert to 0-based index

            // Reverse the substring from Li to Ri
            while (Li < Ri) {
                char temp = S[Li];
                S[Li] = S[Ri];
                S[Ri] = temp;
                Li++;
                Ri--;
            }
        }

        printf("Case #%d: %s\n", t, S);
    }

    return 0;
}