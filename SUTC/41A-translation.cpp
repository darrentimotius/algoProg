#include <stdio.h>
#include <string.h>

int main() {
    char S[105];
    scanf("%s", S);

    char S2[105];
    scanf("%s", S2);
    int l = strlen(S2);

    char newS[105];

    for (int i = 0, j = l - 1; i < l, j >= 0; i++, j--) {
        newS[i] = S2[j];
    }
    newS[l] = '\0';
    if (strcmp(S, newS) == 0) printf("YES\n");
    else printf("NO\n");

    return 0;
}