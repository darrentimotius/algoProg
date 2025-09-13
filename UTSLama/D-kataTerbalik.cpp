#include <stdio.h>
#include <string.h>

int main() {
    char S[35];
    scanf("%[^\n]", S);

    int l = strlen(S);
    int j = 0;

    char newWord[35];
    for (int i = 0; i <= l; i++) {
        if (S[i] == ' ' || S[i] == '\0') {
            newWord[j] = '\0'; // masukin kata sebelum spasi lansung ke array newWord
            for (int k = j - 1; k >= 0; k--) {
                printf("%c", newWord[k]);
            }
            if (S[i] == ' ') printf(" ");
            j = 0;
        } else {
            newWord[j++] = S[i];
        }
    }
    printf("\n");
    return 0;
}