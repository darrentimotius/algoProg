#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n + 5];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int target;
    scanf("%d", &target);

    int sum = 0, start = 0, found = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        while (sum > target && start <= i) {
            sum -= arr[start];
            start++;
        }

        if (sum == target) {
            for (int j = start; j <= i; j++) {
                printf("%d ", arr[j]);
            }
            puts("");
            found = 1;
            break;
        }
    }
    return 0;
}