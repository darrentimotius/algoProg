#include <stdio.h>

int kelipatan = 0;

int recursion(int A) {
    if (A % 3 == 0 && A != 0) kelipatan++;
    else if (A == 1) return 2;
    else if (A == 0) return 1;
    else if (A % 5 == 0) return A * 2;
    else return recursion(A - 1) + A + recursion(A - 2) + A - 2;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);

        kelipatan = 0;
        
        printf("Case #%d: ", tc);
        printf("%d ", recursion(N));
        printf("%d\n", kelipatan);

    }
    return 0;
}