#include<stdio.h>
#define MAX 50
int queue_array[MAX];
int rear=-1;
int front=-1;
void display()
{
    int i;
    if(front==-1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue is :\n");
        for(i=front;i<=rear;i++)
            printf("%d",queue_array[i]);
        printf("\n");
    }
}
void insert(int ele) {
    if (rear == MAX - 1)
        printf("Queue overflow\n");
     else {
        if (front == -1) front = 0;
        rear++;
        queue_array[rear] = ele;
        printf("Inserted %d into queue\n", ele);
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
    } else {
        printf("Deleted element is %d\n", queue_array[front]);
        front++;
        if (front > rear) {
            front = rear = -1; // Reset when queue is empty
        }
    }
}

int main() {
    int ele, choice;

    while (1) {
        printf("\n--- Queue Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &ele);
                insert(ele);
                break;

            case 2:
                delete();
                break;

            case 3:
                if (front == -1)
                    printf("Queue is empty\n");
                else {
                    printf("Queue elements: ");
                    for (int i = front; i <= rear; i++)
                        printf("%d ", queue_array[i]);

                    printf("\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Wrong choice! Please try again.\n");
        }
    }
}


