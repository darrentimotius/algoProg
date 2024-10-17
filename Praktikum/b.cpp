#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Generate random
    srand(time(NULL));
    // printf("%d\n", rand());

    // coin -> head or tail
    // 0 -> head
    // 1 -> tail
    int coin = rand() % 2;
    printf("%d\n", coin);


    // random angka -> 10-15
    // gapnya antara 10-15 ada 6 angka (15-10+1)
    int random = rand() % 6 + 10;
    printf("%d\n", random);
    return 0;
}