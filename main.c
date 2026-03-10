#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct{
    int id;
    char name[50];
    int quantity;
    int price;
}Item;

void loadData(Item items[], int *count);
void printTitle(char title[], int padding);
void printMenu(int count);
void addItem(Item items[], int *count);
void viewAllItem(Item items[], int count);
int searchItem(Item items[], int count);
void updateItem(Item items[], int count);
void deleteItem(Item items[], int *count);
void updateStock(Item items[], int count);
void updateSales(Item items[], int count);
void saveData(Item items[], int count);

int main(){

    char title[] = "**INVENTORY MANAGEMENT SYSTEM**";
    int padding = (40 - strlen(title)) / 2;

    int choice = 0;
    Item items[100];
    int count = 0;
    loadData(items, &count);

    do{
        #ifdef _WIN32                       // Clears the interface each time menu loop repeats
            system("cls");
        #else
            system("clear");
        #endif

        printTitle(title, padding);
        printMenu(choice);
        scanf("%d", &choice);


        switch (choice){
            case 1:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                addItem(items, &count);
                printf("Press ENTER to continue!");
                getchar();
                break;

            case 2:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                viewAllItem(items, count);
                printf("Press ENTER to continue!");
                getchar();
                break;

            case 3:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                searchItem(items, count);
                printf("Press ENTER to continue!");
                getchar();
                getchar();
                break;

            case 4:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                updateItem(items, count);
                printf("Press ENTER to continue!");
                getchar();
                getchar();
                break;

            case 5:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                deleteItem(items, &count);
                printf("Press ENTER to continue!");
                getchar();
                break;

            case 6:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                updateStock(items, count);
                printf("Press ENTER to continue!");
                getchar();
                getchar();
                break;

            case 7:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                updateSales(items, count);
                printf("Press ENTER to continue!");
                getchar();
                getchar();
                break;

            case 8:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                saveData(items, count);
                printf("Press ENTER to continue!");
                getchar();
                getchar();
                break;

            default:
                break;
        }
        
        
    } while (choice != 8);
    




    return 0;
}

void loadData(Item items[], int *count){
    FILE *pFile = fopen("inventory.dat", "rb");

    if (pFile == NULL){
        *count = 0;
        fclose(pFile);
        return;
    }

    fread(count, sizeof(int), 1, pFile);
    fread(items, sizeof(Item), *count, pFile);

    fclose(pFile);
}

void printTitle(char title[], int padding){
    printf("========================================\n");

    for (int i = 0; i < padding; i++){
        printf(" ");
    }

    printf("%s\n", title);

    printf("========================================\n");
}

void printMenu(int choice){
    printf("1. Add Item\n");
    printf("2. View All Items\n");
    printf("3. Search Item by Id\n");
    printf("4. Update Item\n");
    printf("5. Delete Item\n");
    printf("6. Update Stocks\n");
    printf("7. Update Sales\n");
    printf("8. Save & Exit\n");
    printf("\n");
    printf("Enter your choice: ");
}

void addItem(Item items[], int *count){
    printf("Item ID: ");

    if(scanf("%d", &items[*count].id) != 1){
    printf("Invalid input! ID must be a nubmer!");
    while(getchar() != '\n');
    return;
    }
    getchar();

    printf("Item Name: ");
    fgets(items[*count].name, sizeof(items[*count].name), stdin);
    items[*count].name[strcspn(items[*count].name, "\n")] = '\0';

    printf("Quantity: ");
    if(scanf("%d", &items[*count].quantity) != 1){
        printf("Invalid input! Quantity must be a number!");
        while(getchar() != '\n');
        return;
    }
    getchar();

    printf("Price: ");
    if(scanf("%d", &items[*count].price) != 1){
        printf("Invalid input! Price must be a nubmer");
        while(getchar() != '\n');
        return;
    }
    getchar();
    
    (*count)++;
    printf("\nItem Added successfully!\n");
}

void viewAllItem(Item items[], int count){
    if (count == 0){
        printf("No items found!");
        return;
    }

    int pageSize = 5;
    int shown = 0;
    char choice;

    while(shown < count){
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("Number of items: %d", count);
        printf("\n====================\n");

        int remaining = count - shown;
        int limit = remaining < pageSize ? remaining : pageSize;

        for (int i = shown; i < shown + limit; i++){
            printf("\nItem : %d\n", i + 1);

            printf("Item Id: %d\n", items[i].id);
            printf("Item Name: %s\n", items[i].name);
            printf("Quantity: %d\n", items[i].quantity);
            printf("Price: %d\n", items[i].price);
        }

        printf("\n");

        shown += limit;

        if (shown >= count){
            printf("\nEnd of the list!\n");
            return;
        }

        printf("Press ENTER to continue and Q to quit: ");
        choice = getchar();

        if(choice == 'Q' || choice == 'q'){
            break;
        }

        getchar();
    }
}

int searchItem(Item items[], int count){
    if(count == 0){
        printf("No Items found!");
    }

    int temp = 0;

    printf("Enter Item Id: ");
    if(scanf("%d", &temp) != 1){
        printf("Invalid Id. Id must be a number!");
        while(getchar() != '\0');
        return -1;
    }

    for(int i = 0; i < count; i++){
        if(temp == items[i].id){
            printf("\nItem %d\n", i + 1);
            printf("Item Id: %d\n", items[i].id);
            printf("Item Name: %s\n", items[i].name);
            printf("Quantity: %d\n", items[i].quantity);
            printf("Price: %d\n", items[i].price);
            return i;
        }
    }

    printf("Item not found!");
    return -1;

}

void updateItem(Item items[], int count){
    int temp = 0;
    int found = 0;

    printf("Enter Item Id: ");
    if(scanf("%d", &temp) != 1){
        printf("Invalid Id! Id must be a number");
        while(getchar() != '\0');
    }

    for(int i = 0; i < count; i++){
        if(temp == items[i].id){
            found = 1;
            printf("\nItem %d\n", i + 1);
            printf("Item Id: %d\n", items[i].id);
            printf("Item Name: %s\n", items[i].name);
            printf("Quantity: %d\n", items[i].quantity);
            printf("Price: %d\n", items[i].price);

            printf("\n");

            printf("Enter New Name: ");
            fgets(items[i].name, sizeof(items[i].name), stdin);
            items[i].name[strcspn(items[i].name, "\n")] = '\0';

            printf("Enter New Price: ");
            if(scanf("%d", &items[i].price) != 1){
                printf("Invalid price! Price must be a number.");
                while(getchar() != '\n');
                return;
            }

            printf("Updated successfully");
            break;
        }
    }

    if(found == 0){
        printf("Item not found!");
    }
}

void deleteItem(Item items[], int *count){
    int temp = 0;
    int index = -1;
    char confirm;

    printf("Enter Item Id: ");
    if(scanf("%d", &temp) != 1){
        printf("Invalid Id! Id must be a number.");
        while(getchar() != '\n');
        return;
    }

    for(int i = 0; i < *count; i++){
        if(temp == items[i].id){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("Item not found!");
        return;
    }

    printf("\nItem %d\n", index + 1);
    printf("Item ID: %d\n", items[index].id);
    printf("Name: %s\n", items[index].name);
    printf("Price: %d\n", items[index].price);

    printf("\nConfirm Delete? (Y/N): ");
    scanf(" %c", &confirm);
    confirm = toupper(confirm);

    if(confirm != 'Y'){
        printf("Deletion Cancelled\n");
        return;
    }

    for(int i = index; i < *count - 1; i++){
        items[i] = items[i + 1];
    }

    (*count)--;
    printf("Item deleted successfully.\n");

}

void updateStock(Item items[], int count){
    int temp = 0;
    int index = -1;

    printf("Enter Item Id: ");
    if(scanf("%d", &temp) != 1){
        printf("Invalid input! Id must be a number.");
        while(getchar() != '\n');
        return;
    }

    for(int i = 0; i < count; i++){
        if(temp == items[i].id){
            index = i;
        }
    }

    if(index == -1){
        printf("Item not found!");
    }

    printf("\nItem %d\n", index + 1);
    printf("Item ID: %d\n", items[index].id);
    printf("Name: %s\n", items[index].name);
    printf("Price: %d\n", items[index].price);
    printf("Item Quantity: %d\n", items[index].quantity);

    printf("New quantity: ");
    if(scanf("%d", &items[index].quantity) != 1){
        printf("Invalid input! Quantity must be a number.");
        while(getchar() != '\n');
        return;
    }

    printf("Stocks Updated successfuylly.");
}

void updateSales(Item items[], int count){
    int temp = 0;
    int index = -1;
    int sold = 0;

    printf("Enter Item Id: ");
    if(scanf("%d", &temp) != 1){
        printf("Invalid input! Id must be a number.");
        while(getchar() != '\n');
        return;
    }

    for(int i = 0; i < count; i++){
        if(temp == items[i].id){
            index = i;
        }
    }

    if(index == -1){
        printf("Item not found!");
    }

    printf("Enter the amount sold: ");
    if(scanf("%d", &sold) != 1){
        printf("Invalid input! Quantity must be a number.");
        while(getchar() != '\n');
        return;
    }

    items[index].quantity = (items[index].quantity) - sold;
    printf("Updated successfully!");
}

void saveData(Item items[], int count){
    FILE *pFile = fopen("inventory.dat", "wb");

    if (pFile == NULL){
        printf("Error saving data!");
        return;
    }

    fwrite(&count, sizeof(int), 1, pFile);
    fwrite(items, sizeof(Item), count, pFile);

    fclose(pFile);

    printf("Data saved successfully!\n");
}