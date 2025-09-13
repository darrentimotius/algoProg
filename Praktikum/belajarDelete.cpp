#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nextInt();
void printMenu();
void create();
void view();
void del();

int productCount = 0;

char productId[1000][1000];
char productName[1000][1000];
char productCategory[1000][1000];
int productPrice[1000];
int isSpicy[1000];

int main() {
    int input = -1;
    do {
        printMenu();
        do {
            printf(">> ");
            input = nextInt();
            if (input < 1 || input > 4) printf("Input must be between 1 to 4!\n");
        } while (input < 1 || input > 4);
        
        switch (input) {
            case 1:
                create();
                break;
            case 2:
                view();
                break;
            case 3:
                del();
                break;
            case 4:
                printf("Thank You For Using Our Menu.....\n");
                return 0;
                break;
    }
    } while(1);
    return 0;
}

int nextInt() {
    int input;
    scanf("%d", &input);
    getchar();
    return input;
}

void printMenu() {
    system("clear");
    printf("Product Management System\n");
    printf("==============================\n");
    printf("1. Insert New Product\n");
    printf("2. View Product\n");
    printf("3. Delete Product\n");
    printf("4. Exit\n");
}

void create() {
    printf("Insert Product ID : ");
    scanf("%[^\n]", productId[productCount]);
    getchar();

    // min 5 char, maks 15 char
    do {
        printf("Insert Product Name : ");
        scanf("%[^\n]", productName[productCount]);
        getchar();

        if (strlen(productName[productCount]) < 5 || strlen(productName[productCount]) > 15)
        printf("Name length must be between 5 to 15 characters\n");
    } while (strlen(productName[productCount]) < 5 || strlen(productName[productCount]) > 15);
    

    printf("Insert Product Category : ");
    scanf("%[^\n]", productCategory[productCount]);
    getchar();

    printf("Insert Product Price : ");
    productPrice[productCount] = nextInt();

    printf("Is Product Spicy [0 / 1] : ");
    isSpicy[productCount] = nextInt();

    productCount++;
}

void view() {
    for (int i = 0; i < productCount; i++) {
        printf("No. %d\n", i + 1);
        printf("Product ID : %s\n", productId[i]);
        printf("Product Name : %s\n", productName[i]);
        printf("Product Category : %s\n", productCategory[i]);
        printf("Product Price : %d\n", productPrice[i]);
        printf("Is Product Spicy : %d\n", isSpicy[i]);
        printf("==============================\n");
    }
    printf("Press ENTER to Continue.....");
    getchar();
}

void del() {
    // Cara Delete
    // 1. View Product
    view();
    printf("Input Product Number to Delete : ");
    int input = nextInt();
    int index = input - 1;

    for (int i = index; i < productCount - 1; i++) {
        strcpy(productId[i], productId[i + 1]);
        strcpy(productName[i], productName[i + 1]);
        strcpy(productCategory[i], productCategory[i + 1]);
        productPrice[i] = productPrice[i + 1];
        isSpicy[i] = isSpicy[i + 1];
    }
    productCount--;
}