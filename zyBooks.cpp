#include <stdio.h>

int main() {
    int input;
    scanf("%d", &input);

    if (input % 100 == 0 && input % 400 == 0) printf("%d - leap year\n", input);
    else if (input % 100 != 0 && input % 4 == 0) printf("%d - leap year\n", input);
    else printf("%d - not a leap year\n", input);
    return 0;
}

/*
START
    DECLARE INTEGER year
    INPUT year
    IF year MOD 100 EQUAL 0 AND year MOD 400 = 0 THEN
        DISPLAY "leap year"
    ELSE IF year MOD 100 NOT EQUAL 0 AND year MOD 4 EQUAL 0 THEN
        DISPLAY "leap year"
    ELSE THEN
        DISPLAY "not a leap year"
    END IF
END
*/