#include <stdio.h>

int main() {
    int d, s, t;
    scanf("%d %d %d", &d, &s, &t);

    if (d > s && d > t) {
        if (s > t) {
            printf("Daging\nSayur\nTelur\n");
        } else printf("Daging\nTelur\nSayur\n");
    } else if (s > d && s > t) {
        if (d > t) {
            printf("Sayur\nDaging\nTelur\n");
        } else printf("Sayur\nTelur\nDaging\n");
    } else if (t > d && t > s) {
        if (d > s) {
            printf("Telur\nDaging\nSayur\n");
        } else printf("Telur\nSayur\nDaging\n");
    }
    return 0;
}