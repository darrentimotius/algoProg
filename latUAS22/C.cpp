#include <stdio.h>
#include <string.h>

int convert(char a[]) {
    if (strcmp(a, "S") == 0) return 0;
    else if (strcmp(a, "M") == 0) return 1;
    else if (strcmp(a, "L") == 0) return 2;
    else if (strcmp(a, "XL") == 0) return 3;
    else if (strcmp(a, "XXL") == 0) return 4;
}

void sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] < a[j + 1]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}



int main() {
    int n;
    scanf("%d", &n);

    int size[6] = {0};
    int start[n + 5];
    int end[n + 5];

    for (int i = 0; i < n; i++) {
        char a[5], b[5];
        scanf("%s %s", a, b);

        // convert huruf jadi angka
        int sizeA = convert(a);
        int sizeB = convert(b);

        // tambahin ke tiap ukuran
        for (int j = sizeA; j <= sizeB; j++) {
            size[j]++;
        }

        start[i] = sizeA;
        end[i] = sizeB;
    }

    printf("Start : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", start[i]);
    }
    printf("\n");

    printf("End : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", end[i]);
    }
    printf("\n");

    printf("Size : ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", size[i]);
    }
    printf("\n");

    // urutin dari ukurang yang paling banyak di pake
    sort(size, 5);

    int sum = 0, count = 0;
    // Greedy's Algorithm with Sorting
    for (int i = 0; i < 5; i++) {
        sum += size[i];

        for (int j = 0; j < n; j++) {
            if (start[j] <= i && end[j] >= i) {
                for (int k = start[j]; k <= end[j]; k++) {
                    size[k]--;
                }
            }
        }

        count++;
        if (sum >= n) break;

        sort(size, 5);
    }

    printf("%d\n", count);

    return 0;
}