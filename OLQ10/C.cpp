#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char arr[10005][30];
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    char target[30];
    scanf("%s", target);

    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i], target) == 0) {
            puts("Found");
            return 0;
        }
    }

    puts("Not Found");
    return 0;
}