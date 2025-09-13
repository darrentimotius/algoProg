#include <stdio.h>
#include <string.h>

char S[1005];
int isPalindrom = 1;
void func(int l) {
    for (int i = 0, j = l - 1; i < l, j >= 0; i++, j--) {
        if (S[i] != S[j]) {
            isPalindrom = 0;
            break;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%s", S);
        int l = strlen(S);
        func(l);

        printf("Case #%d: ", tc);
        if (isPalindrom) printf("yes\n");
        else printf("no\n");

        isPalindrom = 1;
    }
    return 0;
}