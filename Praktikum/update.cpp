#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void printMenu();
void menu1();
void menu2();
void menu3();
void menu4();

// Utilities
int nextInt();
void enterToContinue();

// Attributes
//         [ukuran][panjang length char]
char productId[100][17];
char productName[100][255];
int productPrice[100];
int productCount = 0;

int main() {
    int input = -1;
    do {
        printMenu();
        do {
            printf("[1-5] >> ");
            input = nextInt();
            if (input < 1 || input > 5) printf("Input must be between 1 to 5!\n");
        } while (input < 1 || input > 5);
        if (input == 1) menu1();
        else if (input == 2) menu2();
        else if (input == 3) menu3();
        else if (input == 4) menu4();
        else if (input == 5) return 0;
    } while(1);
    return 0;
}

int nextInt() {
    int input;
    scanf("%d", &input);
    getchar();
    return input;
}

void enterToContinue() {
    printf("Press enter to continue...");
    getchar();
}

void printMenu() {
    system("clear");
    printf("Program Management\n");
    printf("======================\n");
    printf("1. Create\n");
    printf("2. View\n");
    printf("3. Delete\n");
    printf("4. Update\n");
    printf("5. Exit\n");
}

// Create
void menu1() {
    printf("Input Product ID : ");
    scanf("%s", productId[productCount]);
    getchar();

    printf("Input Product Name : ");
    scanf("%[^\n]", productName[productCount]);
    getchar();

    printf("Input Product Price : ");
    productPrice[productCount] = nextInt();

    char confirmationInput;
    do {
        printf("Do you want to add this product? [y/n]\n>> ");
        scanf("%c", &confirmationInput);
        getchar();

        if (confirmationInput != 'y' 
        && confirmationInput != 'Y'
        && confirmationInput != 'n'
        && confirmationInput != 'N') {
            printf("Input must be between y or n!\n");
        }
    } while (confirmationInput != 'y' 
        && confirmationInput != 'Y'
        && confirmationInput != 'n'
        && confirmationInput != 'N');
    if (confirmationInput == 'y' || confirmationInput == 'Y') productCount++;
}

// View
void menu2() {
    if (productCount == 0) printf("There is no product, please insert a new one!\n");
    for (int i = 0; i < productCount; i++) {
        printf("Product No. %d\n", i + 1);
        printf("==============\n");
        printf("Product ID : %s\n", productId[i]);
        printf("Product Name : %s\n", productName[i]);
        printf("Product Price : %d\n", productPrice[i]);
        printf("==============\n");
    }
    enterToContinue();
}

// Delete
void menu3() {
    
}

// Update
void menu4() {
    if (productCount == 0) {
        printf("There is no product, please insert a new one!\n");
        enterToContinue();
    }
    else {
        menu2();
        char productIdTemp[17];
        char productNameTemp[255];
        int productPriceTemp;
        printf("Input product number to update : ");
        int input = nextInt();
        int index = input - 1;
        printf("Input Product ID : ");
        scanf("%s", productIdTemp);
        getchar();

        printf("Input Product Name : ");
        scanf("%[^\n]", productNameTemp);
        getchar();

        printf("Input Product Price : ");
        productPriceTemp = nextInt();

        char confirmationInput;
        do {
            printf("Do you want to add this product? [y/n]\n>> ");
            scanf("%c", &confirmationInput);
            getchar();

            if (confirmationInput != 'y' 
            && confirmationInput != 'Y'
            && confirmationInput != 'n'
            && confirmationInput != 'N') {
                printf("Input must be between y or n!\n");
            }
        } while (confirmationInput != 'y' 
            && confirmationInput != 'Y'
            && confirmationInput != 'n'
            && confirmationInput != 'N');
    if (confirmationInput == 'y' || confirmationInput == 'Y') {
        strcpy(productId[index], productIdTemp);
        strcpy(productName[index], productNameTemp);
        productPrice[index] = productPriceTemp;
    }
    }
}