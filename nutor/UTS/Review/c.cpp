#include <stdio.h>

int main() {
    int countDayInMonth, startDay;
    scanf("%d %d", &countDayInMonth, &startDay); getchar();

    int map[] = {0, 1, 0, -1, -2, -3, 3, 2};

    puts("Mo|Tu|We|Th|Fr");
    puts("--+--+--+--+--");

    int day = map[startDay];

    for (int i = 0; i < 5; i++) {
        for (int i = 0; i < 5; i++, day++) {
            if (i != 0) printf("|");
            if (day > 0 && day <= countDayInMonth) printf("%2d", day);
            else printf("  ");
        }
        day += 2;
        puts("");
        if (day > countDayInMonth) break;
    }

    return 0;
}