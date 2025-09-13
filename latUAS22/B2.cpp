#include <stdio.h>

struct data {
    int arr;
    int flag;
};

int main() {
    int n;
    scanf("%d", &n);

    data dat[100005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &dat[i].arr);
        if (dat[i].arr % 2 == 1) dat[i].flag = 1;
        else dat[i].flag = 0;
    }

    int maxCount = 0, count = 0, idx = 0, bestIdx = 0;

    for (int i = 0; i < n; i++) {
        if (dat[i].flag) {
            if (count == 0) {
                idx = i;
            }
            count++;
            if (count > maxCount) {
                maxCount = count;
                bestIdx = idx;
            }
        } else {
            count = 0;
        }
    }

    printf("%d, karena terdapat rentetan ", maxCount);
    for (int i = bestIdx; i < bestIdx + maxCount; i++) {
        printf("%d ", dat[i].arr);
    }
    printf("yang sebanyak %d.\n", maxCount);

    return 0;
}