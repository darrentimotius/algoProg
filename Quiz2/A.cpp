#include <stdio.h>

struct data {
    char name[1005];
    long long int food;
};

int main() {
    int n;
    scanf("%d", &n);

    data dat[1005];
    for (int i = 0; i < n; i++) {
        long long int t1, t2;
        scanf("%s %lld %lld", dat[i].name, &t1, &t2);

        dat[i].food = t1 * t2;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (dat[j].food == dat[j+1].food) {
                continue;
            } else if (dat[j].food < dat[j+1].food) {
                data temp = dat[j];
                dat[j] = dat[j+1];
                dat[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s %lld\n", dat[i].name, dat[i].food);
    }
    return 0;
}