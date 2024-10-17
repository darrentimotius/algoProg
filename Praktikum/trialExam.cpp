#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char productId[10000][16];
char productName[10000][20];
char productCategory[10000][10];
int productPrice[10000];

int productCount = 0;

int nextInt();
void enterToContinue();
	
void printMenu();

void create();
void view();
void del();

int main() {
	do {
		int input = -1;
		printMenu();
		do {
			printf(">> ");
			input = nextInt();
			if (input < 1 || input > 4) 
				puts("Input must be between 1 to 4");
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
				puts("Thank you for using our program....");
				enterToContinue();
				return 0;
		}
	} while (1);
}

int nextInt() {
	int input;
	scanf("%d", &input);
	getchar();
	return input;
}

void enterToContinue() {
	printf("Press ENTER to continue....");
	getchar();
}

void printMenu() {
	system("clear");
	puts("JO's LemonStand");
	puts("======================");
	puts("1. Create");
	puts("2. View");
	puts("3. Delete");
	puts("4. Exit");
}

void create() {
	// ID
	srand(time(NULL));
	char unique[] = "!@#$&";
	// for (int i = 0; i < 16; i++) {
	// 	char upper = rand () % 26 + 'A';
	// 	char lower = rand () % 26 + 'a';
	// 	char uniq = unique[rand () % 5];
	// 	char final[] = {upper, lower, uniq};
	// 	productId[productCount][i] = final[rand() % 3];
	// }
    for (int i = 0; i < 16; i++) {
        int decider = rand() % 3;
        if (decider == 0) productId[productCount][i] = rand() % 26 + 'A';
        else if (decider == 1) productId[productCount][i] = rand() % 26 + 'a';
        else if (decider == 2) productId[productCount][i] = unique[rand() % 5];
    }
	
	// Name
	do {
		printf("Input product name : ");
		scanf("%s", productName[productCount]);
		getchar();
		if (strlen(productName[productCount]) < 5 || strlen(productName[productCount]) > 20)
			puts("Input must be between 5 to 20");
	} while (strlen(productName[productCount]) < 5 || strlen(productName[productCount]) > 20);
	
	// Category
	do {
		printf("Input product category [Sweet | Sour | Balanced] : ");
		scanf("%s", productCategory[productCount]);
		getchar();
		if (strcmp(productCategory[productCount], "Sweet") != 0 &&
			strcmp(productCategory[productCount], "Sour") != 0 &&
			strcmp(productCategory[productCount], "Balanced") != 0)
			puts("Input must be Sweet or Sour or Balanced");
	} while (strcmp(productCategory[productCount], "Sweet") != 0 &&
			strcmp(productCategory[productCount], "Sour") != 0 &&
			strcmp(productCategory[productCount], "Balanced") != 0);
			
	//Price
	do {
		printf("Input product price : ");
		productPrice[productCount] =  nextInt();
		if (productPrice[productCount] < 7000 || productPrice[productCount] > 19000)
			puts("Input must be between 7000 to 19000");
	} while (productPrice[productCount] < 7000 || productPrice[productCount] > 19000);
	
	// validation
	char validation;
	printf("\nProduct ID : %s\n", productId[productCount]);
	printf("Product Name : %s\n", productName[productCount]);
	printf("Product Category : %s\n", productCategory[productCount]);
	printf("Product Price : %d\n", productPrice[productCount]);
	
	do {
		printf("Are you sure, you want to add this product [y | n] : ");
		scanf("%c", &validation);
		getchar();
		if (validation != 'y' && validation != 'Y' &&
			validation != 'n' && validation != 'N')
				puts("Input must be y or n");
	} while (validation != 'y' && validation != 'Y' &&
			validation != 'n' && validation != 'N');
	
	if (validation == 'y' || validation == 'Y') {
		productCount++;
		puts("Product has been succesfully created");
		enterToContinue();
		return;
	} else {
		puts("Product create has been canceled");
		enterToContinue();
		return;
	}
}
void view() {
	if (productCount == 0) {
		puts("There is no product available");
		enterToContinue();
		return;
	} else {
		for (int i = 0; i < productCount; i++) {
				printf("\nProduct No. %d\n", i + 1);
				printf("Product ID : %s\n", productId[i]);
				printf("Product Name : %s\n", productName[i]);
				printf("Product Category : %s\n", productCategory[i]);
				printf("Product Price : %d\n", productPrice[i]);
				puts("=========================");
		}
		enterToContinue();
		return;
	}
}

void del() {
	if (productCount == 0) {
		puts("There is no product available");
		enterToContinue();
		return;
	} else {
		view();
		
		int input = -1;
		int index = 0;
		
		do {
			printf("Input product number to delete : ");
			input = nextInt();
			index = input - 1;
			if (index < 0 || index > productCount)
				puts("Product doesn't exist");
		} while (index < 0 || index > productCount);
		
		char validation;
		
		do {
			printf("Are you sure, you want to delete this product [y | n] : ");
			scanf("%c", &validation);
			getchar();
			if (validation != 'y' && validation != 'Y' &&
				validation != 'n' && validation != 'N')
					puts("Input must be y or n");
		} while (validation != 'y' && validation != 'Y' &&
				validation != 'n' && validation != 'N');
		
		if (validation == 'y' || validation == 'Y') {
			for (int i = index; i < productCount - 1; i++) {
				strcpy(productId[i], productId[i+1]);
				strcpy(productName[i], productName[i+1]);
				strcpy(productCategory[i], productCategory[i+1]);
				productPrice[i] = productPrice[i+1];
			}
			productCount--;
			puts("Product has been succesfully deleted");
			enterToContinue();
			return;
		} else {
			puts("Product delete has been canceled");
			enterToContinue();
			return;
		}
	}
}