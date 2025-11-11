#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

void enQueueRear() {
    int value;
    printf("\nEnter the value to be added at rear: ");
    scanf("%d", &value);

    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("\nOverflow\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (rear == SIZE - 1)
        rear = 0;
    else
        rear++;

    queue[rear] = value;
}

void enQueueFront() {
    int value;
    printf("\nEnter the value to be added at front: ");
    scanf("%d", &value);

    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("\nOverflow\n");
        return;
    }

    if (front == -1) {
        front = 0;
        rear = 0;
    } else if (front == 0)
        front = SIZE - 1;
    else
        front--;

    queue[front] = value;
}

void deQueueFront() {
    if (front == -1) {
        printf("\nUnderflow\n");
        return;
    }

    printf("\nDeleted element from front: %d\n", queue[front]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == SIZE - 1)
        front = 0;
    else
        front++;
}

void deQueueRear() {
    if (front == -1) {
        printf("\nUnderflow\n");
        return;
    }

    printf("\nDeleted element from rear: %d\n", queue[rear]);

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0)
        rear = SIZE - 1;
    else
        rear--;
}

void display() {
    int i;
    if (front == -1) {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nFront = %d", front);
    printf("\nQueue elements: ");

    for (i = front; i != rear; i = (i + 1) % SIZE)
        printf("%d ", queue[i]);
    printf("%d", queue[i]);

    printf("\nRear = %d\n", rear);
}

int main() {
    int choice;
    do {
        printf("\n1. Insert at Rear");
        printf("\n2. Insert at Front");
        printf("\n3. Delete from Rear");
        printf("\n4. Delete from Front");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enQueueRear(); break;
            case 2: enQueueFront(); break;
            case 3: deQueueRear(); break;
            case 4: deQueueFront(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("\nInvalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
