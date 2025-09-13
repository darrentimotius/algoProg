#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar();

    for (int i = 1; i <= T; i ++) {
        char N[10001];
        scanf("%[^\n]", N);
        getchar();

        // long long int j = 0;
        // for (j = 0; N[j] != '\0'; j++) {
        // }
        // printf("Case #%d; %lld\n", i, j);

        printf("Case #%d: %ld\n", i, strlen(N));
    }
    return 0;
}