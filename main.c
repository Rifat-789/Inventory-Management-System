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

int main(){

    char title[] = "**INVENTORY MANAGEMENT SYSTEM**";
    int padding = (40 - strlen(title)) / 2;

    int choice = 0;
    Item items[100];
    int count = 0;

    do
    {
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


            break;

            case 2:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif


            break;

            case 3:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif


            break;

            case 4:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif


            break;

            case 5:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif


            break;

            case 6:
                #ifdef _WIN32
                    system("cls");
                #else
                    system("clear");
                #endif

                
            break;
        }
        
        
    } while (choice != 6);
    




    return 0;
}