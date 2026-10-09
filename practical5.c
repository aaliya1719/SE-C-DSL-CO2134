#include <stdio.h>

#define MAX 50

int queue[MAX];
int front = -1;
int rear = -1;

// a. Add patient
void addPatient(int patientID)
{
    if (rear == MAX - 1)
    {
        printf("Queue is full!\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = patientID;

    printf("Patient %d added to the queue.\n", patientID);
}

// b. Attend patient
void attendPatient()
{
    if (front == -1 || front > rear)
    {
        printf("No patients waiting.\n");
        return;
    }

    printf("Patient %d is being attended.\n", queue[front]);
    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

// c. View patients
void viewPatients()
{
    int i;

    if (front == -1)
    {
        printf("No patients waiting.\n");
        return;
    }

    printf("Patients currently waiting:\n");

    for (i = front; i <= rear; i++)
    {
        printf("Patient ID: %d\n", queue[i]);
    }
}

// d. Check whether queue is empty
void isQueueEmpty()
{
    if (front == -1)
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");
}

int main()
{
    int choice, patientID;

    while (1)
    {
        printf("\n--- Hospital Patient Registration ---\n");
        printf("1. Add Patient\n");
        printf("2. Attend Patient\n");
        printf("3. View Patients\n");
        printf("4. Check Queue Empty\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Patient ID: ");
                scanf("%d", &patientID);
                addPatient(patientID);
                break;

            case 2:
                attendPatient();
                break;

            case 3:
                viewPatients();
                break;

            case 4:
                isQueueEmpty();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}