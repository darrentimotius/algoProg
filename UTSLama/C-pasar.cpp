#include <stdio.h>

int main() {
    int X, Y, Z;
    scanf("%d %d %d", &X, &Y, &Z);

    long long int apel = X * 5000, jeruk = Y * 6000, nanas = Z * 7000;
    if (apel > jeruk && apel > nanas) printf("%lld Apel\n", apel);
    else if (jeruk > apel && jeruk > nanas) printf("%lld Jeruk\n", jeruk);
    else if (nanas > apel && nanas > jeruk) printf("%lld Nanas\n", nanas);
    else printf("Cancel\n");
    return 0;
}