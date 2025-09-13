#include <stdio.h>

void printMenu();
void menu1();
void menu2();
void menu3();

// bikin product
// 1. Id
// 2. Product Name
// 3. Product Price
// 4. Product Category
// 5. isSpicy

// Untuk mempermudah, menyimpan banyak data menjadi 1
// STRUCT TIDAK BOLEH DIPAKE!!!!
// struct Product {
//     char id[17];
//     char productName[255];
//     int productPrice;
//     char productCategory[50];
//     int isSpicy;
// };

int productCount = 0;

// GLOBAL ARRAY
    char id[100][17];
    char productName[100][255];
    int productPrice[100];
    char productCategory[100][50];
    int isSpicy[100];

int main() {
    int choice = -1;
    do {
        printMenu();
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                menu1();
                break;
            case 2:
                menu2();
                break;
            case 3:
                menu3();
                break;
            case 4:
                return 0;
                break;
        }
    } while (1);
    return 0;
}

// CRUD
// Create Read Update Delete
void printMenu() {
    printf("1. Insert New Product\n");
    printf("2. View Product\n");
    printf("3. Update Product\n");
    printf("4. Exit\n");
    printf(">> ");
}

void menu1() {
    // Insert
    printf("Insert Product ID : ");
    scanf("%[^\n]", id[productCount]);
    getchar();

    printf("Insert Product Name : ");
    scanf("%[^\n]", productName[productCount]);
    getchar();

    printf("Insert Product Price : ");
    scanf("%d", &productPrice[productCount]);
    getchar();

    printf("Insert Product Category : ");
    scanf("%[^\n]", productCategory[productCount]);
    getchar();

    printf("Is Product Spicy [0 \\ 1] : ");
    scanf("%d", &isSpicy[productCount]);
    getchar();

    productCount++;
}

void menu2() {
    // View
    for (int i = 0; i < productCount; i++) {
        printf("No. %d\n", i + 1);
        printf("Product ID : %s\n", id[i]);
        printf("Product Name : %s\n", productName[i]);
        printf("Product Price : %d\n", productPrice[i]);
        printf("Product Category : %s\n", productCategory[i]);
        printf("Is Product Spicy : %d\n", isSpicy[i]);
        printf("====================================\n");
    }
}

void menu3() {
}