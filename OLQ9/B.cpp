#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    char name[1005][1005];
    for (int i = 0; i < N; i++) {
        scanf("%s", name[i]);
    }

    int X = 0;
    scanf("%d", &X);

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (strcmp(name[j], name[j+1]) > 0) {
                char temp[1005];
                strcpy(temp, name[j]);
                strcpy(name[j], name[j+1]);
                strcpy(name[j+1], temp);
            }
        }
    }

    if (X == 0) {
        for (int i = 0; i < N; i++) {
            printf("%s\n", name[i]);
        }
    } else {
        for (int i = N - 1; i >= 0; i--) {
            printf("%s\n", name[i]);
        }
    }

    return 0;
}