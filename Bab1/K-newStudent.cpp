#include <stdio.h>

int main() {
    char N[100];
    char U[100];
    int A;

    scanf("%[^\n]\n%s %d", N, U, &A);
    printf("Name: %s\nNIS: %s\nAge: %d\n", N, U, A);
    return 0;
}