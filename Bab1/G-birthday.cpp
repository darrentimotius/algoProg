#include <stdio.h>

int main() {
    int nama[101];
    scanf("%[^\n]", nama);
    printf("Happy Birthday to %s.\n", nama);
    return 0;
}