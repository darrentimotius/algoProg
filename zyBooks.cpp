#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char input[99999];
    scanf("%d %[^\n]", &N, input); getchar();

    char array[25][15];
    char temp[25];

    int counterKata = 0;
    int counterTemp = 0;
    int l = strlen(input);
    for (int i = 0; i <= l; i++) {
        if (input[i] == ' ' || input[i] == '\0') {
            temp[counterTemp] = '\0';
            strcpy(array[counterKata], temp);
            // printf("i = %d\ntemp = %s\narray kata ke %d = %s\n\n", i, temp, counterKata, array[counterKata]);
            counterKata++;
            counterTemp = 0;
        } else {
            temp[counterTemp] = input[i];
            // printf("i = %d\ninput = %c\ntemp = %s\n\n", i, input[i], temp);
            counterTemp++;
        }
    }

    // sebuah array dianggap string kalo paling belakangnya itu null terminator
    // contohnya "hey\0"

    // printf("string kita awalnya kayak gini : %s\n\nSekarang jadi : \n", input);
    // for (int i = 0; i < N; i++) {
    //     printf("%s\n", array[i]);
    // }
    // printf("\n\n");

    int counterYangSama[25];
    for (int i = 0; i < N; i++) {
        counterYangSama[i]++;
        for (int j = i+1; j < N; j++) {
            if (strcmp(array[i], array[j]) == 0) {
                counterYangSama[i]++;
                counterYangSama[j]++;
                // printf("array[i] = %s\narray[j] = %s\n\n", array[i], array[j]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%s - %d\n", array[i], counterYangSama[i]);
    }
    return 0;
}