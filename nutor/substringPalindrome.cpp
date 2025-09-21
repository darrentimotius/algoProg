#include <stdio.h>
#include <string.h>

int main() {
    char S[1005];
    scanf("%s", S);

    int l = strlen(S);

    char substring[1005][1005];
    int uniqueCount = 0;

    for (int start = 0; start < l; start++) {
        for (int end = start; end < l; end++) {
            int isPalindrome = 1;
            for (int i = start, j = end; i < j; i++, j--) {
                if (S[i] != S[j]) {
                    isPalindrome = 0;
                    break;
                }
            }

            if (isPalindrome == 1) {
                char temp[1005];
                int k = 0;
                for (int i = start; i <= end; i++) {
                    temp[k++] = S[i];
                }
                temp[k] = '\0';

                int found = 0;
                for (int i = 0; i < uniqueCount; i++) {
                    int same = 1, a = 0;
                    while (substring[i][a] != '\0' && temp[a] != '\0') {
                        if (substring[i][a] != temp[a]) {
                            same = 0;
                            break;
                        }
                        a++;
                    }
                    if (substring[i][a] != temp[a]) same = 0;
                    if (same == 1) {
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    strcpy(substring[uniqueCount], temp);
                    uniqueCount++;
                }
            }
        }
    }
    printf("%d\n", uniqueCount);
    return 0;
}
