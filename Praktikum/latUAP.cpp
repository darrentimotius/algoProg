#include <stdio.h>
#include <string.h>

#define gc getchar();

struct Product {
    int id;
    char name[50];
    int price;
};

Product prod[100];

int prodCount = 0;

void create();
void view();
void update();
void sort();
int searchId(int id);
void saveFile();
void loadFile();

int main() {
    int choice = -1;

    do {
        loadFile();
        puts("1. Add Product");
        puts("2. View Products");
        puts("3. Update Products");
        puts("4. Sort by price");
        puts("5. Exit");
        printf(">> ");

        scanf("%d", &choice); gc

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                view();
                break;
            case 3:
                update();
                break;
            case 4:
                sort();
                break;
        }
    } while (choice != 5);
    return 0;
}

void saveFile() {
    FILE *f = fopen("products.txt", "w");

    for (int i = 0; i < prodCount; i++) {
        fprintf(f, "%d#%s#%d\n", prod[i].id, prod[i].name, prod[i].price);
    }

    fclose(f);
}

void loadFile() {
    FILE *f = fopen("products.txt", "r");

    if (f == NULL) {
        puts("Error loading file....");
        return;
    }
    
    prodCount = 0;
    while (fscanf(f, "%d#%[^#]#%d\n", &prod[prodCount].id, prod[prodCount].name, &prod[prodCount].price) != EOF) {
        prodCount++;
    }

    fclose(f);
}

void create() {
    Product newProduct;

    printf("Enter product name: ");
    scanf("%[^\n]", newProduct.name); gc

    printf("Enter product price : ");
    scanf("%d", &newProduct.price); gc

    newProduct.id = prodCount + 1;

    prod[prodCount++] = newProduct;
    saveFile();
}

void view() {
    if (prodCount == 0) {
        puts("There's no product");
        return;
    }

    for (int i = 0; i < prodCount; i++) {
        printf("ID : %d, Name : %s, Price : %d\n", prod[i].id, prod[i].name, prod[i].price);
    }
}

int searchId(int id) {
    for (int i = 0; i < prodCount; i++) {
        if (prod[i].id == id) return i;
    }

    return -1;
}

void update() {
    int toUpdate;
    printf("Enter id to update: ");
    scanf("%d", &toUpdate); gc

    int res = searchId(toUpdate);

    if (res != -1) {
        int newPrice;

        printf("Enter new price: ");
        scanf("%d", &newPrice); gc

        prod[res].price = newPrice;
        saveFile();
    } else {
        puts("Product not found");
    }
}

void swap(Product *a, Product *b) {
    Product temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Product arr[], int l, int h) {
    int i = l - 1;
    for (int j = l; j < h; j++) {
        if (arr[j].price < arr[h].price) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return i + 1;
}

void quick(Product arr[], int l, int h) {
    if (l >= h) return;

    int p = partition(arr, l, h);
    quick(arr, p + 1, h);
    quick(arr, l, h - 1);
} 

void sort() {
    if (prodCount < 0) {
        puts("There is no product to sort");
        return;
    } else {
        quick(prod, 0, prodCount - 1);
        saveFile();
    }
}
