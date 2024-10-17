#include <stdio.h>

void hello() {
    printf("Hello World!\n");
}

//Function
int addition(int angka1, int angka2) {
    printf("Hasil penjumlahan: %d\n", angka1 + angka2);
    return angka1 + angka2;
}

int main() { // entry point
    int a = 10, b = 20;
    addition(a, b);
    return 0;
}

/*
WingWing
1. Insert
2. Delete
3. View
4. exit
*/