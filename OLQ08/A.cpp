#include <stdio.h>

int main() {
    FILE *f = fopen("testdata.in", "r");

    int N;
    fscanf(f, "%d\n", &N);

    unsigned long long int array[55];
    for (int i = 0; i < N; i++) {
        fscanf(f, "%llu", &array[i]);
    }
    fgetc(f);

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (array[j] > array[j+1]) {
                unsigned long int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    int flag = 0;
    for (int i = 0; i < N - 2; i++) {
        if (array[i] + array[i+1] > array[i+2]) {
            flag = 1;
            break;
        }
    }

    if (flag) puts("YES");
    else puts("NO");
    return 0;
}