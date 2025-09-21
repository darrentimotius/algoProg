#include <stdio.h>

int main() {
    int arr[1000];
    int n = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int longest = 0;

    for (int i = 0; i < n; i++) {
        int count = 1;
        int next = arr[i] + 1;

        while (1) {
            int found = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] == next) {
                    found = 1;
                    count++;
                    next++;
                    break;
                }
            }
            if (!found) break;
        }
        if (count > longest) longest = count;
    }

    printf("%d\n", longest);
    return 0;
}