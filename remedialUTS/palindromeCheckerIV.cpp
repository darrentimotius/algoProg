#include <stdio.h>
#include <string.h>

int main() {
    char S[1005], temp[1005];
    scanf("%[^\n]", S); getchar();
    
    int j = 0;
    for (int i = 0; S[i] != '\0'; i++) {
        if (S[i] != ' ') {
            temp[j++] = S[i];
        }
    }
    temp[j] = '\0';

    int l = strlen(temp);

    int isPalindrome = 1;
    for (int i = 0, j = l - 1; i <= j; i++, j--) {
        if (temp[i] != temp[j]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) puts("Yes");
    else puts("No");
    return 0;
}