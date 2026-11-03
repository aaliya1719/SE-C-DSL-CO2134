#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int roll;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int roll)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->roll = roll;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int roll)
{
    if (root == NULL)
        return createNode(roll);

    if (roll < root->roll)
        root->left = insert(root->left, roll);
    else if (roll > root->roll)
        root->right = insert(root->right, roll);
    else
        printf("Roll number already exists!\n");

    return root;
}

struct Node *search(struct Node *root, int roll)
{
    if (root == NULL || root->roll == roll)
        return root;

    if (roll < root->roll)
        return search(root->left, roll);

    return search(root->right, roll);
}

struct Node *findMin(struct Node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

struct Node *deleteNode(struct Node *root, int roll)
{
    struct Node *temp;

    if (root == NULL)
    {
        printf("Student record not found!\n");
        return root;
    }

    if (roll < root->roll)
        root->left = deleteNode(root->left, roll);
    else if (roll > root->roll)
        root->right = deleteNode(root->right, roll);
    else
    {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        temp = findMin(root->right);
        root->roll = temp->roll;
        root->right = deleteNode(root->right, temp->roll);
    }

    return root;
}

// Inorder: Left, Root, Right
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->roll);
        inorder(root->right);
    }
}

// Preorder: Root, Left, Right
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->roll);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder: Left, Right, Root
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->roll);
    }
}

// Main function
int main()
{
    struct Node *root = NULL;
    struct Node *result;
    int choice, roll;

    do
    {
        printf("\n\n--- Student Record Management ---\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Search Student\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter roll number: ");
            scanf("%d", &roll);
            root = insert(root, roll);
            break;

        case 2:
            printf("Enter roll number to delete: ");
            scanf("%d", &roll);

            if (search(root, roll) == NULL)
                printf("Student record not found!\n");
            else
            {
                root = deleteNode(root, roll);
                printf("Student record deleted successfully.\n");
            }
            break;

        case 3:
            printf("Enter roll number to search: ");
            scanf("%d", &roll);

            result = search(root, roll);

            if (result != NULL)
                printf("Student with roll number %d found.\n",
                       result->roll);
            else
                printf("Student record not found!\n");
            break;

        case 4:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            printf("Preorder Traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 6:
            printf("Postorder Traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 7:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 7);

    return 0;
}
