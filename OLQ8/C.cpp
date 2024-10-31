#include <stdio.h>
#include <string.h>
#define mod 1000000007

int main() {
    FILE *f = fopen("testdata.in", "r");
    char array[105][105];
    int count = 0;
    while (!feof(f)) {
        fscanf(f, "%s\n", array[count]);
        count++;
    }

    long long int output = 1;
    for (int i = 0; i < count; i++) {
        int l = strlen(array[i]);
        for (int j = 0; j < l; j++) {
            if ((array[i][j] == ';' && j == 0) || (array[i][j] == ';' && array[i][j-1] == ';')) {
                output *= 101;
                output %= mod;
            }
        }
    }

    printf("%lld\n", output);
    return 0;
}