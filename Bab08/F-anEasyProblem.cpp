#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        if (temp) {
            puts("not easy");
            return 0;
        }
    }

    puts("easy");
    return 0;
}