#include <stdio.h>

// total = (n * (n + 1)) / 2

int main() {
    int n;
    scanf("%d", &n);

    int arr[n + 5], sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int N = n + 1;
    int total = (N * (N + 1)) / 2;

    printf("%d\n", total - sum);
    return 0;
}