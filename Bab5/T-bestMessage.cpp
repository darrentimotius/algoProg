#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);

    char A[] = {'A', 'B', 'C', 'D', '\0', '\0'};
    char E[] = {'E', 'F', 'G', 'H', '\0', '\0'};
    char I[] = {'I', 'J', 'K', 'L', 'M', 'N'};
    char O[] = {'O', 'P', 'Q', 'R', 'S', 'T'};
    char U[] = {'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    for (int tc = 1; tc <= T; tc++) {
        char message[1005];
        scanf("%s", message); getchar();

        int l = strlen(message);

        int key[l+5] = {0};
        printf("Case #%d:\n", tc);
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < 6; j++) {
                if (message[i] == A[j]) {
                    printf("A");
                    key[i] = j;
                }
                else if (message[i] == E[j]) {
                    printf("E");
                    key[i] = j;
                }
                else if (message[i] == I[j]) {
                    printf("I");
                    key[i] = j;
                }
                else if (message[i] == O[j]) {
                    printf("O");
                    key[i] = j;
                }
                else if (message[i] == U[j]) {
                    printf("U");
                    key[i] = j;
                }
            }
            if (i == l - 1) printf("\n");
        }

        for (int i = 0; i < l; i++) {
            printf("%d", key[i]);
            if (i == l - 1) printf("\n");
        }
    }
    return 0;
}

/*
a b c d
0 1 2 3

e f g h
0 1 2 3

i j k l m n
0 1 2 3 4 5

o p q r s t
0 1 2 3 4 5

u v w x y z
0 1 2 3 4 5


0 1 2 3 4
b i n u s
a i i u o
2 1 6 1 5

array lokasi huruf
index :
0 1 2 3 4 5
2 1 6

i = 0, j = 0
i = b, j = a false
i = 0, j = 1
i = b, j = b true
print 'A'
array lokasi huruf ke i = j + 1
i = 1, j = 0
i = i, j = i true
print 'I'
array lokasi huruf ke 1(i) = 0(j) + 1
i = 2, j = 0
i = n, j = i false
i = 2, j = 1
i = n, j = j false
i = 2, j = 2
i = n, j = k false
i = 2, j = 3
i = n, j = l false
i = 2, j = 4
i = n, j = m false
i = 2, j = 5
i = n, j = n true
print 'I'
array lokasi huruf ke 2(i) = 5(j) + 1
*/