#include <stdio.h>

int main() {
    FILE *f = fopen("testdata.in", "r");
    int N;
    fscanf(f, "%d\n", &N);
    char array[10005];
    fscanf(f, "%s", array);

    int count = 0;
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] == '1') {
            count++;
        } else {
            count = 0;
        }
        if (count > max) max = count;
    }

    printf("%d\n", max);
    return 0;
}