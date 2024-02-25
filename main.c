#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include this for strtok
#include "StrList.h"
#define MAX 1000

int main() {
    StrList *list = StrList_alloc();
    int choice = 0;
    char data[MAX];
    int index;

    do {
          if (scanf("%d", &choice) != 1) {
            //printf("Invalid input. Please enter a number.");
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                //printf("Enter how many word do you mean to enter: ");
                int x;
                scanf("%d%*c", &x); // קריאה למשתנה וניקוי תו זבל
                //printf("Enter the strings to insert separated by spaces: ");
                scanf("%[^\n]s", data); // Change format to %[^\n]
                char *token = strtok(data, " ");
                while (token != NULL && x>0) {
                    StrList_insertLast(list, token);
                    token = strtok(NULL, " ");
                    x--;
                }
                break;
            case 2:
                //printf("Enter the index to insert: ");
                scanf("%d", &index);
                //printf("Enter the string to insert: ");
                scanf(" %[^\n]s", data);
                StrList_insertAt(list, data, index);
                break;
            case 3:
                //printf("List contents:");
                if(list==NULL){return 0;}
                else{StrList_print(list);}
                break;
            case 4:
            printf("%zu", StrList_size(list));
                //printf("Length of the list: %zu", StrList_size(list));
                break;
            case 5:
                //printf("Enter the index: ");
                scanf("%d", &index);
                //printf("your data");
                StrList_printAt(list, index);
                break;
            case 6:
            printf("%d", StrList_printLen(list));
                //printf("Total number of characters in the list: %d", StrList_printLen(list));
                break;
            case 7:
                //printf("Enter the string to count: ");
                scanf(" %[^\n]s", data);
                printf("%d", StrList_count(list, data));
                //printf("Occurrences of \"%s\": %d", data, StrList_count(list, data));
                break;
            case 8:
                //printf("Enter the string to remove: ");
                scanf(" %[^\n]s", data);
                StrList_remove(list, data);
                break;
            case 9:
                //printf("Enter the index to remove: ");
                scanf("%d", &index);
                StrList_removeAt(list, index);
                break;
            case 10:
                StrList_reverse(list);
                //printf("List reversed.");
                break;
            case 11:
                StrList_free(list);
                list = StrList_alloc();
                //printf("List deleted.");
                break;
            case 12:
                StrList_sort(list);
                //printf("List sorted.");
                break;
            case 13:
                if (StrList_isSorted(list))
                    printf("True");
                else
                    printf("False");
                break;
            case 0:
                //printf("Exiting program.");
                break;
            default:
                return 0;//printf("Invalid choice!");
        }
    }
    while (choice != 0);
    return 0;
    
}
