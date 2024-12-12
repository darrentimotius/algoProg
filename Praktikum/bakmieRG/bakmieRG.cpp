#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define gc getchar();

struct data {
	char id[100];
	char nama[1000];
	char kategori[100];
	int stock;
	int price;
};

data bakmie[1000];
int bakmieCount = 0;

void merge(data bakmie[], int left, int mid, int right);
void sort(data bakmie[], int left, int right);

void saveFile();
void loadFile();

void printMenu();
void enterToContinue();

void searchCategory(char type[]);
void viewAll();

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
		
		switch (input) {
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
	FILE *f = fopen("bakmie.dat", "w");
	
	if (f == NULL) {
		puts("Error loading file");
		enterToContinue();
		return;
	}
	
	for (int i = 0; i < bakmieCount; i++) {
		fprintf(f, "%s#%s#%s#%d#%d\n", bakmie[i].id, bakmie[i].nama, bakmie[i].kategori, 
				bakmie[i].stock, bakmie[i].price);
	}
	
	fclose(f);
}

void loadFile() {
	FILE *f = fopen("bakmie.dat", "r");
	
	if (f == NULL) {
		puts("Error loading file");
		enterToContinue();
		return;
	}
	
	bakmieCount = 0;
	
	while (fscanf(f, "%[^#]#%[^#]#%[^#]#%d#%d\n", bakmie[bakmieCount].id,
			bakmie[bakmieCount].nama, bakmie[bakmieCount].kategori, 
			&bakmie[bakmieCount].stock, &bakmie[bakmieCount].price) != EOF)
				bakmieCount++;
	
	fclose(f);
}

void printMenu() {
	loadFile();
	system("cls");
	puts(" ____        _              _      _____   _____");
	puts("|  _ \\      | |            (_)    |  __ \\ / ____|");
	puts("| |_) | __ _| | ___ __ ___  _  ___| |__) | |  __ ");
	puts("|  _ < / _` | |/ / '_ ` _ \\| |/ _ \\  _  /| | |_ |");
	puts("| |_) | (_| |   <| | | | | | |  __/ | \\ \\| |__| |");
	puts("|____/ \\__,_|_|\\_\\_| |_| |_|_|\\___|_|  \\_\\\\_____|");
	puts("1. Create Bakmie");
	puts("2. View Bakmie");
	puts("3. Buy Bakmie");
	puts("4. Exit");
}

void enterToContinue() {
	puts("Press ENTER to continue...."); gc
}

void merge(data bakmie[], int left, int mid, int right) {
	int i = left, j = mid + 1, k = left;
	data temp[right + 5];
	
	while (i <= mid && j <= right) {
		if (strcmp(bakmie[i].nama, bakmie[j].nama) < 0) {
			temp[k] = bakmie[i];
			k++;
			i++; 
		} else {
			temp[k] = bakmie[j];
			k++;
			j++;
		}
	}
	
	while (i <= mid) {
		temp[k] = bakmie[i];
		k++;
		i++;
	}
	
	while (j <= right) {
		temp[k] = bakmie[j];
		k++;
		j++;
	}
	
	for (i = left; i <= right; i++) {
		bakmie[i] = temp[i];
	}
}

void sort(data bakmie[], int left, int right) {
	if (left >= right) return;
	
	int mid = left + (right - left) / 2;
	
	sort(bakmie, left, mid);
	sort(bakmie, mid + 1, right);
	merge(bakmie, left, mid, right);
}

void create() {
	data temp;
	
	// Name
	do {
		printf("Input bakmie name : ");
		scanf("%[^\n]", temp.nama); gc
	} while (strlen(temp.nama) <= 3);
	
	// Category
	do {
		printf("Choose category [Lebar / Kecil / Keriting] : ");
		scanf("%s", temp.kategori); gc
	} while (strcmp(temp.kategori, "Lebar") != 0 && strcmp(temp.kategori, "Kecil") != 0 &&
			strcmp(temp.kategori, "Keriting") != 0);
	
	// Stock
	do {
		printf("Input bakmie stock : ");
		scanf("%d", &temp.stock); gc
	} while (temp.stock <= 0);
	
	// Price
	do {
		printf("Input bakmie price : ");
		scanf("%d", &temp.price); gc
	} while (!(temp.price > 10000));
	
	// ID
	sprintf(temp.id, "%c%c%d%d%d", temp.nama[0], temp.nama[1],
			rand() % 10, rand() % 10, rand() % 10);
	
	bakmie[bakmieCount++] = temp;
	sort(bakmie, 0, bakmieCount - 1);
	saveFile();
	puts("Bakmie has been successfully created");
	enterToContinue();
}

void searchCategory(char type[]) {
	int flag = 0, count = 1;
	for (int i = 0; i < bakmieCount; i++) {
		if (strcmp(type, bakmie[i].kategori) == 0) {
			printf("No. %d\n", count);
			printf("ID : %s\n", bakmie[i].id);
			printf("Name : %s\n", bakmie[i].nama);
			printf("Category : %s\n", bakmie[i].kategori);
			printf("Stock : %d\n", bakmie[i].stock);
			printf("Price : %d\n", bakmie[i].price);
			puts("==================");
			count++, flag = 1;
		}
	}
	if (!flag) puts("There is no product in this category");
}

void viewAll() {
	for (int i = 0; i < bakmieCount; i++) {
		printf("No. %d\n", i + 1);
		printf("ID : %s\n", bakmie[i].id);
		printf("Name : %s\n", bakmie[i].nama);
		printf("Category : %s\n", bakmie[i].kategori);
		printf("Stock : %d\n", bakmie[i].stock);
		printf("Price : %d\n", bakmie[i].price);
		puts("==================");
	}
}

void view() {
	if (bakmieCount == 0) {
		puts("There is no bakmie");
		enterToContinue();
		return;
	}
	
	int type;
	puts("1. All");
	puts("2. Lebar");
	puts("3. Kecil");
	puts("4. Keriting");
	puts("5. Back");
	
	do {
		printf(">> ");
		scanf("%d", &type); gc
	} while (type < 1 || type > 5);
	
	switch (type) {
		case 1 :
			viewAll();
			break;
		case 2 :
			searchCategory("Lebar");
			break;
		case 3 :
			searchCategory("Kecil");
			break;
		case 4 :
			searchCategory("Keriting");
			break;
		case 5 :
			return;
	}
	enterToContinue();
}

void buy() {
	if (bakmieCount == 0) {
		puts("There is no bakmie");
		enterToContinue();
		return;
	}
	
	viewAll();
	
	char target[100];
	int flag = 0, indexLoc = -1;
	do {
		printf("Input bakmie name : ");
		scanf("%[^\n]", target); gc
		
		for (int i = 0; i < bakmieCount; i++) {
			if (strcmp(target, bakmie[i].nama) == 0) {
				flag = 1;
				indexLoc = i;
				break;
			}
		}
	} while (strlen(target) <= 3 || !flag);
	
	int toBuy = -1;
	do {
		printf("Input quantity to buy : ");
		scanf("%d", &toBuy); gc
	} while (toBuy <= 0 || toBuy > bakmie[indexLoc].stock);
	
	if (toBuy < bakmie[indexLoc].stock) bakmie[indexLoc].stock -= toBuy;
	else {
		for (int i = indexLoc; i < bakmieCount - 1; i++) {
			bakmie[i] = bakmie[i + 1];
		}
		bakmieCount--;
	}
	
	saveFile();
	
	puts("Bakmie has been successfully bought");
	enterToContinue();
}

