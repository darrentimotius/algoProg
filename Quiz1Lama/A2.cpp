#include <stdio.h>
#include <string.h>

int main() {
    char S[1005];
    scanf("%s", S);

    int l = strlen(S);
    int flagHuruf[1005] = {0};
    int count = 0;
    for (int i = 0; i < l; i++) {
        if (flagHuruf[S[i] - 'a'] == 0) {
            flagHuruf[S[i] - 'a'] = 1;
            count++;
        }
    }

    for (int i = 0; i < l; i++) {
        if (i + 2 > l) break;
        if (S[i] == S[i+2]) count++;
    }

    int isPalindrome = 1;
    for (int i = 0, j = l - 1; i < l, j >= 0; i++, j--) {
        if (S[i] != S[j]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome == 1) count++;

    printf("%d\n", count);
    return 0;
}