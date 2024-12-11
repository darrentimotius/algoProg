#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define gc getchar();

struct item {
	char id[10];
	char name[100];
	char category[100];
	int stock;
	int price;
};

item yupi[1000];
int yupiCount = 0;

void saveFile();
void loadFile();

void printMenu();
void enterToContinue();

void create();
void view();
void buy();

int main() {
	do {
		srand(time(0));
		int input = -1;
		printMenu();
		
		do {
			printf(">> ");
			scanf("%d", &input); gc
		} while (input < 1 || input > 4);
		
		switch(input) {
			case 1 :
				create();
				break;
			case 2 :
				view();
				break;
			case 3 :
				buy();
				break;
			case 4 :
				puts("Thank you for using our program");
				enterToContinue();
				return 0;
		}
	} while (1);
	return 0;
}

void saveFile() {
	FILE *f = fopen("candy.txt", "w");
	 
	if (f == NULL) {
		puts("Error loading file....");
		enterToContinue();
		return;
	}
	
	for (int i = 0; i < yupiCount; i++) {
		fprintf(f, "%s#%s#%s#%d#%d\n", yupi[i].id, yupi[i].name,
			yupi[i].category, yupi[i].stock, yupi[i].price);
	}
	
	fclose(f);
}

void loadFile() {
	FILE *f = fopen("candy.txt", "r");
	
	if (f == NULL) {
		puts("Error loading file....");
		enterToContinue();
		return;
	}
	
	yupiCount = 0;
	
	while (fscanf(f, "%[^#]#%[^#]#%[^#]#%d#%d\n", yupi[yupiCount].id, yupi[yupiCount].name,
			yupi[yupiCount].category, &yupi[yupiCount].stock, &yupi[yupiCount].price) != EOF)
				yupiCount++;
	
	fclose(f);
}

void printMenu() {
	system("cls");
	loadFile();
	puts(" __     __          _  _____ _                 ");
	puts(" \\ \\   / /         (_)/ ____| |                ");
	puts("  \\ \\_/ /   _ _ __  _| (___ | |_ ___  _ __ ___ ");
	puts("   \\   / | | | '_ \\| |\\___ \\| __/ _ \\| '__/ _ \\");
	puts("    | || |_| | |_) | |____) | || (_) | | |  __/");
	puts("    |_| \\__,_| .__/|_|_____/ \\__\\___/|_|  \\___|");
	puts("             | |                               ");
	puts("             |_|                               ");
	
	puts("1. Create Candy");
	puts("2. View Candy");
	puts("3. Buy Candy");
	puts("4. Exit");
}

void enterToContinue() {
	puts("Press ENTER to continue...."); gc
}

void create() {
	item newYupi;
	
	// Name
	do {
		printf("Enter candy name : ");
		scanf("%[^\n]", newYupi.name); gc
		
		if (strlen(newYupi.name) < 8 || strlen(newYupi.name) > 20)
			puts("Input must be between 8 to 20");
	} while (strlen(newYupi.name) < 8 || strlen(newYupi.name) > 20);
	
	// Category
	do {
		printf("Enter candy category [Choco / Gummy / Minty / Fruity] : ");
		scanf("%s", newYupi.category); gc
		
		if (strcmp(newYupi.category, "Choco") != 0 &&
			strcmp(newYupi.category, "Gummy") != 0 &&
			strcmp(newYupi.category, "Minty") != 0 &&
			strcmp(newYupi.category, "Fruity") != 0)
				puts("Input must be Choco / Gummy / Minty / Fruity");
	} while (strcmp(newYupi.category, "Choco") != 0 &&
			strcmp(newYupi.category, "Gummy") != 0 &&
			strcmp(newYupi.category, "Minty") != 0 &&
			strcmp(newYupi.category, "Fruity") != 0);
	
	// Stock
	do {
		printf("Enter candy stock : ");
		scanf("%d", &newYupi.stock); gc
		
		if (newYupi.stock <= 0)
			puts("Input must be greater than 0");
	} while (newYupi.stock <= 0);
	
	// Price
	do { 
		printf("Enter candy price : ");
		scanf("%d", &newYupi.price); gc
		
		if (newYupi.stock <= 0)
			puts("Input must be greater than 0");
	} while (newYupi.stock <= 0);
	
	// ID
	sprintf(newYupi.id, "%c%c%03d", newYupi.name[0], newYupi.name[1], yupiCount + 1);
	
	// Validation
	printf("ID : %d\n", newYupi.id);
	printf("Name : %s\n", newYupi.name);
	printf("Category : %s\n", newYupi.category);
	printf("Stock : %d\n", newYupi.stock);
	printf("Price : %d\n", newYupi.price);
	
	char validation[10];
	printf("Are you sure want to add candy [yes / no] : ");
	
	do {
		scanf("%s", validation); gc
		
		if (strcmp(validation, "Yes") != 0 && strcmp(validation, "No") != 0 &&
			strcmp(validation, "yes") != 0 && strcmp(validation, "no") != 0)
				puts("Input must be yes or no");
	} while (strcmp(validation, "Yes") != 0 && strcmp(validation, "No") != 0 &&
			strcmp(validation, "yes") != 0 && strcmp(validation, "no") != 0);
	
	if (strcmp(validation, "yes") == 0 || strcmp(validation, "Yes") == 0) {
		yupi[yupiCount++] = newYupi;
		saveFile();
		puts("Candy succesfully created");
	} else puts("Create candy has been canceled");
	
	enterToContinue();
}

void merge(item yupi[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;
	item temp[right + 5];
	
	while (i <= mid || j <= right) {
		if (strcmp(yupi[i].name, yupi[j].name) > 0) {
			temp[k] = yupi[i];
			k++;
			i++;
		} else {
			temp[k] = yupi[j];
			k++;
			j++;
		}
	}
	
	while (i <= mid) {
		temp[k] = yupi[i];
			k++;
			i++;
	}
	
	while (j <= right) {
		temp[k] = yupi[j];
			k++;
			j++;
	}
	
	for (i = left; i <= right; i++) {
		yupi[i] = temp[i];
	}
}

void sort(item yupi[], int left, int right) {
	if (left >= right) return;
	
	int mid = left + (right - left) / 2;
	
	sort(yupi, left, mid);
	sort(yupi, mid + 1, right);
	merge(yupi, left, mid, right);
}

void view() {
	if (yupiCount == 0) {
		puts("There is no candy");
		enterToContinue();
		return;
	}
	
	// Validation
	char validation[100];
	printf("Choose view mode [all / Choco / Gummy / Minty / Fruity] : ");
	
	do {
		scanf("%s", validation); gc
		
		if (strcmp(validation, "all") != 0 && strcmp(validation, "Choco") != 0 &&
			strcmp(validation, "Gummy") != 0 && strcmp(validation, "Minty") != 0 &&
			strcmp(validation, "Fruity") != 0)
				puts("Input must be all / Choco / Gummy / Minty / Fruity");
	} while (strcmp(validation, "all") != 0 && strcmp(validation, "Choco") != 0 &&
			strcmp(validation, "Gummy") != 0 && strcmp(validation, "Minty") != 0 &&
			strcmp(validation, "Fruity") != 0);
	
	if (strcmp(validation, "all") == 0) {
		sort(yupi, 0, yupiCount - 1);
		for (int i = 0; i < yupiCount; i++) {
			printf("No. %d\n", i + 1);
			printf("ID : %s\n", yupi[i].id);
			printf("Name : %s\n", yupi[i].name);
			printf("Category : %s\n", yupi[i].category);
			printf("Stock : %d\n", yupi[i].stock);
			printf("Price : %d\n", yupi[i].price);
			puts("=======================");
		}
	} else {
		int count = 1, flag = 0;
		for (int i = 0; i < yupiCount; i++) {
			if (strcmp(yupi[i].category, validation) == 0) {
				flag = 1;
				printf("No. %d\n", count);
				printf("ID : %s\n", yupi[i].id);
				printf("Name : %s\n", yupi[i].name);
				printf("Category : %s\n", yupi[i].category);
				printf("Stock : %d\n", yupi[i].stock);
				printf("Price : %d\n", yupi[i].price);
				puts("=======================");
				count++;
			}
		}
		
		if (!flag) puts("There is no product in that category");
	}
	
	enterToContinue();
}

void buy() {
	if (yupiCount == 0) {
		puts("There is no candy");
		enterToContinue();
		return;
	}
	
	// Name
	char name[100];
	do {
		printf("Enter candy name : ");
		scanf("%[^\n]", name); gc
		
		if (strlen(name) < 8 || strlen(name) > 20)
			puts("Input must be between 8 to 20");
	} while (strlen(name) < 8 || strlen(name) > 20);
	
	int quantityLoc = 0;
	for (int i = 0; i < yupiCount; i++) {
		if (strcmp(yupi[i].name, name) == 0) {
			quantityLoc = i;
			break;
		}
	}
	
	int toBuy = 0;
	do {
		printf("Enter candy quantity you want to buy : ");
		scanf("%d", &toBuy); gc
		
		if (toBuy > yupi[quantityLoc].stock || toBuy < 0) puts("Quantity must not exceed the available stock");
	} while (toBuy > yupi[quantityLoc].stock || toBuy < 0);
	
	if (toBuy < yupi[quantityLoc].stock) yupi[quantityLoc].stock -= toBuy;
	else {
		for (int i = quantityLoc; i < yupiCount - 1; i++) {
			yupi[i] = yupi[i + 1];
		}
		yupiCount--;
	}
	saveFile();
	puts("Candy has been successfully bought");
	enterToContinue();
}
