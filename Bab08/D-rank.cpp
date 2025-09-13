#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T); getchar();
    
    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N); getchar();
        char nama[1005][15];
        int nilai[1005];
        for (int i = 0; i < N; i++) {
            scanf("%[^#]#%d", nama[i], &nilai[i]); getchar();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - 1; j++) {
                if (nilai[j] < nilai[j+1]) {
                    int tempNilai = nilai[j];
                    nilai[j] = nilai[j+1];
                    nilai[j+1] = tempNilai;

                    char tempNama[15];
                    strcpy(tempNama, nama[j]);
                    strcpy(nama[j], nama[j+1]);
                    strcpy(nama[j+1], tempNama);
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - 1; j++) {
                if (nilai[j] == nilai[j+1]) {
                    if (strcmp(nama[j], nama[j+1]) > 0) {
                        char tempNama[15];
                        strcpy(tempNama, nama[j]);
                        strcpy(nama[j], nama[j+1]);
                        strcpy(nama[j+1], tempNama);
                    }
                }
            }
        }

        char search[15];
        scanf("%s", search); getchar();

        printf("Case #%d: ", tc);
        for (int i = 0; i < N; i++) {
            if (strcmp(nama[i], search) == 0) printf("%d\n", i+1);
        }
    }
    return 0;
}