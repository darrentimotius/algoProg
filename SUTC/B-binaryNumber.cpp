#include <stdio.h>
#include <string.h>

int main() {
    char S[1000005];
    scanf("%s", S);

    int count = 0, len = strlen(S);

    for (int i = len - 1; i > 0; i--) {
        if (S[i] == '0') count++;
        else if (S[i] == '1') {
            count += 2;
            S[i - 1]++;
        }
        else {
            count++;
            S[i - 1]++;
        }
    }

    if (S[0] == '2') count++;
    printf("%d\n", count);
    return 0;
}