#include <stdio.h>

struct data {
    int arr;
    int count = 0;
};

int main() {
    int n;
    scanf("%d", &n);

    data dat[100005];
    int count = 0;

    int maxCount = 0;
    for(int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);

        int found = -1;
        for (int i = 0; i < count; i++) {
            if (dat[i].arr == temp) {
                found = i;
                break;
            }
        }

        if (found == -1) {
            dat[count].arr = temp;
            dat[count].count++;
            count++;
        } else dat[found].count++;

        if (dat[found].count > maxCount) maxCount = dat[found].count;
    }

    for (int i = 0; i < count; i++) {
        if (dat[i].count == maxCount) {
            printf("%d, karena angka %d terdapat %d duplikat\n", dat[i].arr, dat[i].arr, dat[i].count);
        }
    }
    return 0;
}