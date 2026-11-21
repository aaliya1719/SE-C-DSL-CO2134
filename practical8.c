#include <stdio.h>

#define TABLE_SIZE 10
#define EMPTY -1

int hashTable[TABLE_SIZE];

// Initialize the hash table
void initialize()
{
    int i;

    for (i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = EMPTY;
    }
}

// Insert a book ID using linear probing
void insertBook(int key)
{
    int index, pos, i;

    index = key % TABLE_SIZE;

    for (i = 0; i < TABLE_SIZE; i++)
    {
        pos = (index + i) % TABLE_SIZE;

        if (hashTable[pos] == EMPTY)
        {
            hashTable[pos] = key;
            printf("Book ID inserted successfully.\n");
            return;
        }

        if (hashTable[pos] == key)
        {
            printf("Book ID already exists.\n");
            return;
        }
    }

    printf("Hash table is full.\n");
}

// Search for a book ID using linear probing
void searchBook(int key)
{
    int index, pos, i;

    index = key % TABLE_SIZE;

    for (i = 0; i < TABLE_SIZE; i++)
    {
        pos = (index + i) % TABLE_SIZE;

        if (hashTable[pos] == EMPTY)
        {
            printf("Book ID not found.\n");
            return;
        }

        if (hashTable[pos] == key)
        {
            printf("Book ID found at position %d.\n", pos);
            return;
        }
    }

    printf("Book ID not found.\n");
}

// Display the hash table
void display()
{
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] == EMPTY)
            printf("Position %d: EMPTY\n", i);
        else
            printf("Position %d: %d\n", i, hashTable[i]);
    }
}

int main()
{
    int choice, key;

    initialize();

    do
    {
        printf("\n--- Library Book Indexing ---\n");
        printf("1. Insert Book ID\n");
        printf("2. Search Book ID\n");
        printf("3. Display Hash Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Book ID: ");
            scanf("%d", &key);

            if (key < 0)
                printf("Please enter a non-negative Book ID.\n");
            else
                insertBook(key);
            break;

        case 2:
            printf("Enter Book ID to search: ");
            scanf("%d", &key);

            if (key < 0)
                printf("Please enter a non-negative Book ID.\n");
            else
                searchBook(key);
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}