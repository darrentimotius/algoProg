#include <stdio.h>
#include <string.h>

char S[1001];

void func(int l) {
    for (int i = l - 1; i >= 0; i--) {
        printf("%c", S[i]);
    }
}

int main() {
    int T;
    scanf("%d", &T); getchar();

    for (int tc = 1; tc <= T; tc++) {
        scanf("%[^\n]", S); getchar();
        int l = strlen(S);
        printf("Case #%d: ", tc);
        func(l);
        printf("\n");
    }
    return 0;
}