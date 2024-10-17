#include <stdio.h>

int main() {
    FILE *file;

    file = fopen("testdata.in", "r");
    int A, B;
    fscanf(file, "%d %d", &A, &B);
    printf("%d\n", A + B);
    return 0;
}