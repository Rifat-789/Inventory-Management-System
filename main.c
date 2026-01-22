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

int main(){

    char title[] = "**INVENTORY MANAGEMENT SYSTEM**";
    int padding = (40 - strlen(title)) / 2;

    int choice = 0;
    Item items[100];
    int count = 0;

    do{
        #ifdef _WIN32                       // Clears the interface each time menu loop repeats
            system("cls");
        #else
            system("clear");
        #endif



        switch (choice){
            case 1:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                printf("Press ENTER to continue!");
                getchar();
                getchar();
                break;

            case 2:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                printf("Press ENTER to continue!");
                getchar();
                getchar();
                break;

            case 3:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

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

                printf("Press ENTER to continue!");
                getchar();
                getchar();
                break;

            case 6:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                printf("Press ENTER to continue!");
                getchar();
                getchar();
                break;

            default:
                break;
        }
        
        
    } while (choice != 6);
    




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

void printMenu(int count){
    printf("1. Add Item\n");
    printf("2. View All Items\n");
    printf("3. Search Item by Id\n");
    printf("4. Update item\n");
    printf("5. Delete Item\n");
    printf("6. Save and Exit\n");
    printf("\n");
    printf("Enter your choice: ");
}