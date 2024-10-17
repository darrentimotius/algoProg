#include <stdio.h>
#include <string.h>

int main() {
    char S[1005];
    scanf("%s", S);
    int l = strlen(S);

    int count = 0;
    int count2 = 0;
    int notPolindrome = 0;
    for (int i = 0, j = l - 1; i < l, j >= 0; i++, j--) {
        if (S[i] == S[j]) {
            count++;
            count2++;
        }
        if (S[i] != S[j]) {
            if (count > 0) count = l - count;
            notPolindrome = 1;
            break;
        }
        if (i >= j) {
            count++;
            break;
        }
    }
    
    int isSmallPolindrome = 0;
    for (int i = 0; i < l - 2; i++) {
        if (S[i] == S[i+2]) {
            isSmallPolindrome = 1;
            count++;
        }
    }

    if (notPolindrome == 1 || isSmallPolindrome == 0) {
        int temp = l - count - count2;
        count += temp;
    }


    printf("%d\n", count);
    return 0;
}