#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    int isDirectory;
    struct Node *firstChild;
    struct Node *nextSibling;
    struct Node *parent;
};

struct Node *root;
struct Node *current;

// Find an item inside the current directory
struct Node* findChild(struct Node *parent, char name[]) {
    struct Node *temp = parent->firstChild;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp;
        }
        temp = temp->nextSibling;
    }

    return NULL;
}

// Insert a new file or directory
void addItem(int type) {
    char name[50];
    struct Node *newNode, *temp;

    printf("Enter name: ");
    scanf("%49s", name);

    if (findChild(current, name) != NULL) {
        printf("An item with this name already exists!\n");
        return;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newNode->name, name);
    newNode->isDirectory = type;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    newNode->parent = current;

    if (current->firstChild == NULL) {
        current->firstChild = newNode;
    }
    else {
        temp = current->firstChild;

        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }

        temp->nextSibling = newNode;
    }

    if (type == 1) {
        printf("Directory created successfully!\n");
    }
    else {
        printf("File created successfully!\n");
    }
}

// Create a directory
void createDirectory() {
    addItem(1);
}

// Create a file
void createFile() {
    addItem(0);
}

// Search for a file or directory
void searchTree(struct Node *node, char name[], int *found) {
    while (node != NULL) {
        if (strcmp(node->name, name) == 0) {
            printf("\nItem Found!\n");
            printf("Name: %s\n", node->name);
            printf("Type: %s\n",
                   node->isDirectory ? "Directory" : "File");

            printf("Location: ");
            // Display the item's complete path
            struct Node *path[100];
            int i = 0;
            struct Node *temp = node;

            while (temp != NULL && i < 100) {
                path[i++] = temp;
                temp = temp->parent;
            }

            while (i > 0) {
                printf("%s", path[--i]->name);
                if (i > 0) {
                    printf("/");
                }
            }
            printf("\n");

            *found = 1;
        }

        if (node->isDirectory) {
            searchTree(node->firstChild, name, found);
        }

        node = node->nextSibling;
    }
}

// Search by name
void searchItem() {
    char name[50];
    int found = 0;

    printf("Enter file/folder name to search: ");
    scanf("%49s", name);

    searchTree(root, name, &found);

    if (found == 0) {
        printf("Item not found!\n");
    }
}

// Display directory structure
void displayTree(struct Node *node, int level) {
    int i;

    while (node != NULL) {
        for (i = 0; i < level; i++) {
            printf("    ");
        }

        printf("|-- %s", node->name);

        if (node->isDirectory) {
            printf(" [Directory]\n");
            displayTree(node->firstChild, level + 1);
        }
        else {
            printf(" [File]\n");
        }

        node = node->nextSibling;
    }
}

// Display complete hierarchy
void displayStructure() {
    printf("\n========== DIRECTORY STRUCTURE ==========\n");
    printf("%s [Root_Directory]\n", root->name);

    if (root->firstChild == NULL) {
        printf("Directory is empty!\n");
        return;
    }

    displayTree(root->firstChild, 1);
}

// Navigate between directories
void navigateDirectory() {
    char name[50];
    struct Node *temp;

    printf("\nCurrent Location: %s\n", current->name);
    printf("Enter directory name or '..' to go back: ");
    scanf("%49s", name);

    if (strcmp(name, "..") == 0) {
        if (current->parent != NULL) {
            current = current->parent;
            printf("Moved to parent directory.\n");
        }
        else {
            printf("Already at root directory!\n");
        }
        return;
    }

    temp = findChild(current, name);

    if (temp == NULL) {
        printf("Directory not found!\n");
    }
    else if (temp->isDirectory == 0) {
        printf("Cannot navigate into a file!\n");
    }
    else {
        current = temp;
        printf("Directory opened successfully!\n");
    }
}

// Rename a file or directory
void renameItem() {
    char oldName[50], newName[50];
    struct Node *temp, *duplicate;

    printf("Enter current name: ");
    scanf("%49s", oldName);

    temp = findChild(current, oldName);

    if (temp == NULL) {
        printf("Item not found!\n");
        return;
    }

    printf("Enter new name: ");
    scanf("%49s", newName);

    duplicate = findChild(current, newName);

    if (duplicate != NULL && duplicate != temp) {
        printf("An item with this name already exists!\n");
        return;
    }

    strcpy(temp->name, newName);
    printf("Item renamed successfully!\n");
}

// Delete a file or an empty directory
void deleteItem() {
    char name[50];
    struct Node *temp, *prev;

    printf("Enter name to delete: ");
    scanf("%49s", name);

    temp = current->firstChild;
    prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (temp->isDirectory && temp->firstChild != NULL) {
                printf("Directory is not empty! Cannot delete.\n");
                return;
            }

            if (prev == NULL) {
                current->firstChild = temp->nextSibling;
            }
            else {
                prev->nextSibling = temp->nextSibling;
            }

            free(temp);
            printf("Item deleted successfully!\n");
            return;
        }

        prev = temp;
        temp = temp->nextSibling;
    }

    printf("Item not found!\n");
}

// Count files and directories
void countItems(struct Node *node, int *files, int *directories) {
    while (node != NULL) {
        if (node->isDirectory) {
            (*directories)++;
            countItems(node->firstChild, files, directories);
        }
        else {
            (*files)++;
        }

        node = node->nextSibling;
    }
}

// Display total count
void displayCount() {
    int files = 0, directories = 0;

    countItems(root->firstChild, &files, &directories);

    printf("\n========== ITEM COUNT ==========\n");
    printf("Total Directories : %d\n", directories);
    printf("Total Files       : %d\n", files);
    printf("Total Items       : %d\n", files + directories);
}

// Free allocated memory
void freeTree(struct Node *node) {
    if (node == NULL) {
        return;
    }

    freeTree(node->firstChild);
    freeTree(node->nextSibling);
    free(node);
}

// Main function
int main() {
    int choice;

    root = (struct Node*)malloc(sizeof(struct Node));

    if (root == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    strcpy(root->name, "ROOT");
    root->isDirectory = 1;
    root->firstChild = NULL;
    root->nextSibling = NULL;
    root->parent = NULL;

    current = root;

    do {
        printf("\n========================================\n");
        printf("          SMARTFILE MANAGER\n");
        printf("       File & Directory System\n");
        printf("========================================\n");

        printf("Current Location: %s\n", current->name);

        printf("\n1. Create Directory\n");
        printf("2. Create File\n");
        printf("3. Search File/Directory\n");
        printf("4. Display Directory Structure\n");
        printf("5. Navigate Directory\n");
        printf("6. Rename File/Directory\n");
        printf("7. Delete File/Directory\n");
        printf("8. Count Files & Directories\n");
        printf("9. Exit\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            choice = 0;
            continue;
        }

        switch (choice) {
        case 1:
            createDirectory();
            break;

        case 2:
            createFile();
            break;

        case 3:
            searchItem();
            break;

        case 4:
            displayStructure();
            break;

        case 5:
            navigateDirectory();
            break;

        case 6:
            renameItem();
            break;

        case 7:
            deleteItem();
            break;

        case 8:
            displayCount();
            break;

        case 9:
            freeTree(root);
            printf("Memory released successfully!\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}
