#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t); getchar();

    for (int tc = 0; tc < t; tc++) {
        char s[100];
        scanf("%s", s); getchar();

        int l = strlen(s);
        // printf("Case #%d: ", tc + 1);
        for (int i = 0; i < l; i++) {
            printf("%c", s[i]);
            // printf("i = %d", i);
            if (s[i] != s[i + 1] || i == l - 1) printf("1");
            else {
                // printf(" masuk else\n");
                int c = 0;
                for (int j = i; j < l; j++) {
                    // printf("i = %d\n", i); 
                    if (s[i] == s[j]) c++;
                    else break;
                }
                printf("%d", c);
                i += c - 1;
                // printf("c = %d, i = %d\n", c, i);
            }
        }
        puts("");
    }
    return 0;
}