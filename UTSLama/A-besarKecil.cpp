#include <stdio.h>
#include <string.h>

int main() {
    char S[100];
    scanf("%[^\n]", S);
    getchar();

    int l = strlen(S);
    for (int i = 0; i < l; i++) {
        if (S[i] == ' ') continue;
        else if (S[i] >= 'a') S[i] = S[i] - 'a' + 'A';
        else S[i] = S[i] - 'A' + 'a';
    }

    printf("%s\n", S);
    return 0;
}