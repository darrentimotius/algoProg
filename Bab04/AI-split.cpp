#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int N;
        scanf("%d", &N);

        int array[N], totalSum = 0, runningSum = 0;

        // Read the array and calculate the total sum
        for (int j = 0; j < N; j++) {
            scanf("%d", &array[j]);
            totalSum += array[j];
        }

        // Check if the total sum is odd
        // If it is, print "No" and continue to the next test case
        if (totalSum % 2 != 0) {
            printf("Case #%d: No\n", i);
            continue;
        }
        
        // Check if the running sum is equal to the total sum divided by 2
        // If it is, print "Yes" and break the loop
        for (int j = 0; j < N; j++) {
            runningSum += array[j];
            if (runningSum == (totalSum / 2)) {
                printf("Case #%d: Yes\n", i);
                break;
            }
        }

        // If the running sum is not equal to the total sum divided by 2
        // Print "No"
        if (runningSum != (totalSum / 2)) {
            printf("Case #%d: No\n", i);
        }
    }
return 0;
}