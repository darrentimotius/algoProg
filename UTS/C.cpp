#include <stdio.h>

int main() {
    int countDayInMonth, startDay;
    scanf("%d %d", &countDayInMonth, &startDay);

    int map[] = {0, 1, 0, -1, -2, -3, 3, 2};

    puts("Mo|Tu|We|Th|Fr");
    puts("--+--+--+--+--");

    int day = map[startDay];

    for (int i = 0; i < 5; i++) {
        for (int i = 0; i < 5; i++, day++) {
            if (i != 0) printf("|");
            if (0 < day && day <= countDayInMonth) printf("%2d", day);
            else printf("  ");
        }
        day += 2;
        printf("\n");
        if (day > countDayInMonth) break;
    }
    return 0;
}