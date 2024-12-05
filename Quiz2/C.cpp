#include <stdio.h>
#include <string.h>

void swap (char a[], char b[]) {
    char temp[105];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int partition(char s[][105], int low, int high) {
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (strcmp(s[j], s[high]) < 0) {
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i+1], s[high]);
    return i + 1;
}

void quick(char s[][105], int low, int high) {
    if (low > high) return;
    int p = partition(s, low, high);
    quick(s, p + 1, high);
    quick(s, low, p - 1);
}

int main() {
    int n;
    scanf("%d", &n);

    char s[10005][105];
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }

    int p;
    scanf("%d", &p);

    char target[105];
    scanf("%s", target);

    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = 0; j < n - 1 - i; j++) {
    //         if (strcmp(s[j], s[j+1]) > 0) {
    //             char temp[105];
    //             strcpy(temp, s[j]);
    //             strcpy(s[j], s[j+1]);
    //             strcpy(s[j+1], temp);
    //         }
    //     }
    // }
    quick(s, 0, n - 1);

    // for (int i = 0; i < n; i++) {
    //     printf("%s\n", s[i]);
    // }

    int loc = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(target, s[i]) == 0) {
            loc = i + 1;
            break;
        }
    }

    if (!loc) {
        puts("Not Found");
        return 0;
    }

    printf("Found at ");
    if (loc % p == 0) printf("%d\n", loc / p);
    else printf("%d\n", loc / p + 1);
    return 0;
}