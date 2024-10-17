#include <stdio.h>
#include <string.h>

int main() {
    // Assign value to array
    // data_type variable_name[size];
    int n[5] = {1, 2, 3, 4, 5};
    
    // Change value of array
    n[3] = 100;

    // Print all value of array
    // for (int i = 0; i < 5; i++) {
    //     printf("%d\n", n[i]);
    // }


    // String -> Array of char
    // Array of string ->
    // size kiri -> kebawah
    // size kanan -> kesamping
    char stringArr[100][25];

    // strcpy(destination, source)
    strcpy(stringArr[0], "Hello");
    strcpy(stringArr[1], "World");
    strcpy(stringArr[2], "aku");
    strcpy(stringArr[3], "buffalo");

    for (int i = 0; i < 4; i++) {
        printf("%s\n", stringArr[i]);
    }

    printf("\n\n\n%c\n", stringArr[0][0]);
    /*
      0 1 2 3 4 5 6 7 8 9
    1 h e l l o
    2 w o r l d
    3 a k u
    4 b u f f a l o
    5
    */
    return 0;
}