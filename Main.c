#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "StrList.h"
#define MAX 1000

int main() {
    StrList *list = StrList_alloc();
    int choice = 0;
    char data[MAX];
    int index;

    do {
          if (scanf("%d", &choice) != 1) {
            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:// Insert words at the end of the list
                int x;
                scanf("%d%*c", &x); 
                scanf("%[^\n]s", data);// Read the words separated by spaces
                char *token = strtok(data, " ");
                while (token != NULL && x>0) {// Insert each token into the list
                    StrList_insertLast(list, token);
                    token = strtok(NULL, " ");
                    x--;
                }
                break;
            case 2:// Insert a word at a specific index in the list
                scanf("%d", &index);
                scanf(" %[^\n]s", data);
                StrList_insertAt(list, data, index);
                break;
            case 3:// Print the list
                if(list==NULL){return 0;}
                else{StrList_print(list);printf("\n");}
                break;
            case 4:// Print the size of the list
            printf("%zu", StrList_size(list));
                printf("\n");
                break;
            case 5:// Print the element at a specific index
                scanf("%d", &index);
                StrList_printAt(list, index);
                printf("\n");
                break;
            case 6:// Print the total number of characters in the list
            printf("%d", StrList_printLen(list));
                printf("\n");
                break;
            case 7:// Count occurrences of a word in the list
                scanf(" %[^\n]s", data);
                printf("%d", StrList_count(list, data));
                printf("\n");
                break;
            case 8:// Remove a word from the list
                scanf(" %[^\n]s", data);
                StrList_remove(list, data);
                break;
            case 9:// Remove a word at a specific index
                scanf("%d", &index);
                StrList_removeAt(list, index);
                break;
            case 10:// Reverse the list
                StrList_reverse(list);
                break;
            case 11:// Free the memory allocated for the list and create a new empty list
                StrList_free(list);
                list = StrList_alloc();
                break;
            case 12:// Sort the list
                StrList_sort(list);
                break;
            case 13:// Check if the list is sorted
                if (StrList_isSorted(list)){printf("true");printf("\n");}
                    
                else{printf("false");printf("\n");}

                break;
            case 0:// Exit the program
                break;
            default:// Invalid choice
                return 0;
        }
    }
    while (choice != 0);// Continue until the user chooses to exit
    return 0;
    
}
