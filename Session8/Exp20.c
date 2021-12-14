#include <stdio.h>
#include <stdlib.h>
typedef struct Queue Q;
struct Queue
{
    int data;
    Q *next;
} *front = NULL, *rear = NULL;

void enQueue(int val)
{
    Q *new_node = (Q *)malloc(sizeof(Q));
    if (new_node == NULL)
    {
        printf("Queue is full , insertion is not possible.\n");
    }
    else
    {
        new_node->data = val;
        new_node->next = NULL;
        if (rear == NULL)
        {
            front = new_node;
            rear = new_node;
        }
        else
        {
            rear->next = new_node;
            rear = new_node;
        }
    }
}

void deQueue()
{
    if (front == NULL)
    {
        printf("Queue is empty , deletion is not possible.\n");
    }
    else
    {
        Q *temp;
        temp = front;
        printf("dequeued element is %d\n", front->data);
        if (front == rear)
        {
            front = NULL;
            rear = NULL;
        }
        else
        {
            front = front->next;
        }
        free(temp);
    }
}
void displayQueue()
{
    if (front == NULL)
    {
        printf("Queue is empty , nothing to display.\n");
    }
    else
    {
        Q *temp;
        temp = front;
        while (temp != NULL)
        {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{

    int value, option;

    do
    {

        printf("Select the opertaion you want to perform. Enter 0 to exit.\n");
        printf("1. enqueue() , 2. dequeue() , 3. displayQueue() , 4. clearscreen()\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 0:
            break;
        case 1:
            printf("enter the element you want to enqueue: ");
            scanf("%d", &value);
            enQueue(value);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            displayQueue();
            break;

        case 4:
            system("cls");
        default:
            printf("wrong input.\n");
            break;
        }

    } while (option != 0);
    return 0;
}