#include <stdio.h>
#include <string.h>

struct Item {
    char name[30];
    int price;
    int stock;
};

Item itemList[100];
int counter = 0;

void create();
void view();
void del();

int main() {
    int choice = -1;

    do {
        puts("1. Create Item");
        puts("2. View Item");
        puts("3. Delete Item");
        puts("4. Exit");
        printf(">> ");
        scanf("%d", &choice); getchar();

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                view();
                break;
            case 3:
                del();
                break;
        }
    } while (choice != 4);
    return 0;
}

/*
w -> write
a -> append
r -> read
*/

void create() {
    FILE *f = fopen("items.txt", "a");

    if (f == NULL) {
        puts("File not found!");
        return;
    }

    Item newItem;
    printf("Enter Item name: ");
    scanf("%[^\n]", newItem.name); getchar();

    printf("Enter item price : ");
    scanf("%d", &newItem.price); getchar();

    printf("Enter item stock : ");
    scanf("%d", &newItem.stock); getchar();

    fprintf(f, "%s#%d#%d\n", newItem.name, newItem.price, newItem.stock);
    fclose(f);
}
void view() {
    FILE *f = fopen("items.txt", "r");

    if (f == NULL) {
        puts("File not found!");
        return;
    }
    
    Item item;
    while (fscanf(f, "%[^#]#%d#%d\n", item.name, &item.price, &item.stock) != EOF) {
        printf("Name : %s, Price : %d, Stock : %d\n", item.name, item.price, item.stock);
    }

    fclose(f);
}
void del() {
    FILE *f = fopen("items.txt", "r");

    if (f == NULL) {
        puts("File not found!");
        return;
    }

    char toDelete[30];
    printf("Enter item to delete: ");
    scanf("%[^\n]", toDelete); getchar();

    Item item;
    Item deletedItem;

    int found = 0;

    while (fscanf(f, "%[^#]#%d#%d\n", item.name, &item.price, &item.stock) != EOF) {
        if (strcmp(item.name, toDelete) != 0 || found == 1) {
            strcpy(itemList[counter].name, item.name);
            itemList[counter].price = item.price;
            itemList[counter].stock = item.stock;
            counter++;
        } else {
            strcpy(deletedItem.name, item.name);
            deletedItem.price = item.price;
            deletedItem.stock = item.stock;
            found = 1;
        }
    }

    fclose(f);

    if (found == 1) {
        FILE *f = fopen("items.txt", "w");
        for (int i = 0; i < counter; i++) {
            fprintf(f, "%s#%d#%d\n", itemList[i].name, itemList[i].price, itemList[i].stock);
        }

        printf("%s %d %d has been deleted!\n", deletedItem.name, deletedItem.price, deletedItem.stock);
    }
    else puts ("Item not found!");
}
