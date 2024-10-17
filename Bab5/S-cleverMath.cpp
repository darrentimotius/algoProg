#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int A, B;
        scanf("%d %d", &A, &B);

        int res = 0;
        int place = 1;
        while (A > 0 || B > 0) {
            // get the last digit of A and B
            int digitA = A % 10;
            int digitB = B % 10;

            // add the last digit of A and B
            int sum = (digitA + digitB) % 10;
            
            // add the sum to the result
            // and multiply it with the place value
            res += sum * place;
            // move to the next place
            place *= 10;

            // move to the next digit of A and B
            A /= 10;
            B /= 10;
        }

        printf("Case #%d: %d\n", tc, res);
    }
    return 0;
}