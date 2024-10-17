#include <stdio.h>

int main() {
    int T;  // Number of test cases
    scanf("%d", &T);  // Read the number of test cases
    
    for (int t = 1; t <= T; t++) {
        int N;  // Number of boxes
        scanf("%d", &N);  // Read the number of boxes
        
        int max1 = -1000001;  // Initialize the largest value
        int max2 = -1000001;  // Initialize the second largest value
        
        for (int i = 0; i < N; i++) {
            int value;
            scanf("%d", &value);  // Read each box's value
            
            // Update the two largest values
            if (value > max1) {
                max2 = max1;
                max1 = value;
            } else if (value > max2) {
                max2 = value;
            }
        }
        
        // Output the result for this test case
        printf("Case #%d: %d\n", t, max1 + max2);
    }
    
    return 0;
}
