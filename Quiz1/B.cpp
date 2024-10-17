#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int arr[N+5];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }

    for (int i = 0; i < N; i++) {
        if (sum % 2 == 1 && arr[i] % 2 == 1) sum -= arr[i];
    }
    printf("%lld\n", sum);
    return 0;
}