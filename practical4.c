// Browser Navigation System using two stacks

#include <stdio.h>
#include <string.h>

#define MAX 50
#define SIZE 100

int main()
{
    char backStack[MAX][SIZE];
    char forwardStack[MAX][SIZE];

    int backTop = -1;
    int forwardTop = -1;

    char currentPage[SIZE] = "Home";
    char newPage[SIZE];

    int choice;

    do
    {
        printf("\n\n===== BROWSER NAVIGATION =====\n");
        printf("1. Visit New Page\n");
        printf("2. Back\n");
        printf("3. Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        // Visit New Page
        case 1:
            printf("Enter page name: ");
            scanf("%s", newPage);

            // Push current page into Back Stack
            backTop++;
            strcpy(backStack[backTop], currentPage);

            // Change current page
            strcpy(currentPage, newPage);

            // Clear Forward Stack
            forwardTop = -1;

            printf("Current Page: %s\n", currentPage);
            break;

        // Back Navigation
        case 2:
            if (backTop == -1)
            {
                printf("No previous page available!\n");
            }
            else
            {
                // Push current page into Forward Stack
                forwardTop++;
                strcpy(forwardStack[forwardTop], currentPage);

                // Pop page from Back Stack
                strcpy(currentPage, backStack[backTop]);
                backTop--;

                printf("Current Page: %s\n", currentPage);
            }
            break;

        // Forward Navigation
        case 3:
            if (forwardTop == -1)
            {
                printf("No forward page available!\n");
            }
            else
            {
                // Push current page into Back Stack
                backTop++;
                strcpy(backStack[backTop], currentPage);

                // Pop page from Forward Stack
                strcpy(currentPage, forwardStack[forwardTop]);
                forwardTop--;

                printf("Current Page: %s\n", currentPage);
            }
            break;

        // Display Current Page
        case 4:
            printf("Current Page: %s\n", currentPage);
            break;

        // Exit
        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
