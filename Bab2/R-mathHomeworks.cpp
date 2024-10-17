#include <stdio.h>

int main() {
    long long int a, b, c, d, a1, b1, c1, d1, a2, b2, c2, d2;
    scanf("(%lld+%lld)x(%lld-%lld)", &a, &b, &c, &d);
    getchar();
    scanf("(%lld+%lld)x(%lld-%lld)", &a1, &b1, &c1, &d1);
    getchar();
    scanf("(%lld+%lld)x(%lld-%lld)", &a2, &b2, &c2, &d2);
    getchar();
    printf("%lld %lld %lld\n", (a+b)*(c-d), (a1+b1)*(c1-d1), (a2+b2)*(c2-d2));
    return 0;
}