#include <stdio.h>
#include <string.h>

int main() {
    for (int i = 0; i < 2; i++) {
        char S1[25], S2[25], S3[25];
        scanf("%s %s %s", S1, S2, S3);
        printf("%sszs %sszs %sszs\n", S1, S2, S3);
    }
    return 0;
}