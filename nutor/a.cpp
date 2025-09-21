#include <stdio.h>
#define gc getchar();

int main() {
    int map[10] = {0, 1, 0, -1, -2, -3, 3, 2};

    int countDay, startDay;
    scanf("%d %d", &countDay, &startDay); gc

    puts("Mo|Tu|We|Th|Fr");
    puts("--+--+--+--+--");

    int day = map[startDay];
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++, day++) {
            if (j != 1) printf("|");
            if (0 < day && day <= countDay) printf("%2d", day);
            else printf("  ");

        }
        day += 2;
        puts("");
    }
    return 0;
}