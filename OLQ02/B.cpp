#include <stdio.h>

int main() {

    char S1[10], S2[10], S3[10], S4[10], S5[10];
    scanf("%[^\n] %[^\n] %[^\n] %[^\n] %[^\n]", S1, S2, S3, S4, S5);

    printf("%10s|%s\n", S1, S1);
    printf("%10s|%s\n", S2, S2);
    printf("%10s|%s\n", S3, S3);
    printf("%10s|%s\n", S4, S4);
    printf("%10s|%s\n", S5, S5);
    return 0;
}