#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void createQueue(struct Queue *q)
{
    q->size = 5;
    q->Q = (int *)malloc(q->size * sizeof(int));
    q->front = -1;
    q->rear = -1;
}
int isQueueEmpty(struct Queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isQueueFull(struct Queue *q)
{
    if ((q->rear == (q->front - 1)) || (q->front == 0 && q->rear == (q->size - 1)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct Queue *q, int data)
{
    if (isQueueFull(q))
    {
        printf("Queue is full , can't perform enqueue.\n");
    }
    else if (isQueueEmpty(q))
    {
        q->front = 0;
        q->rear = (q->rear + 1) % (q->size);
        q->Q[q->rear] = data;
        printf("Element enqueued at 1st position.\n");
    }
    else
    {
        q->rear = (q->rear + 1) % (q->size);
        q->Q[q->rear] = data;
        printf("Element enqueued .\n");
    }
}
void dequeue(struct Queue *q)
{

    if (isQueueEmpty(q))
    {
        printf("Queue is empty , Nothing to dequeue!\n");
    }
    else
    {
        printf("deleted elment is %d\n", q->Q[q->front]);
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % (q->size);
        }
    }
}
void displayQueue(struct Queue q)
{
    if (isQueueEmpty(&q))
    {
        printf("Queue is empty , Nothing to display !\n");
    }
    else
    {
        printf("Displaying the elements of Queue: \n");
        int i = q.front;
        if (q.front <= q.rear)
        {
            for (i = q.front; i <= q.rear; i++)
            {
                printf("%d  ", q.Q[i]);
            }
        }
        else
        {

            for (i = q.front; i <= q.size - 1; i++)
            {
                printf("%d  ", q.Q[i]);
            }
            for (int i = 0; i <= q.rear; i++)
            {
                printf("%d  ", q.Q[i]);
            }
            printf("\n");
        }
    }
}

int main()
{
    int value, option;
    struct Queue q1;
    createQueue(&q1);

    do
    {

        printf("\nSelect the opertaion you want to perform. Enter 0 to exit.\n");
        printf("1. enqueue() , 2. dequeue() , 3. displayQueue() , 4. isQueueEmpty() , 5. isQueueFull() , 6. clearscreen()\n");
        
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            break;
        case 1:
            printf("enter the element you want to enqueue: ");
            scanf("%d", &value);
            enqueue(&q1, value);
            break;
        case 2:
            dequeue(&q1);
            break;
        case 3:
            displayQueue(q1);
            break;
        case 4:
            if (isQueueEmpty(&q1))
            {
                printf("Queue is empty .\n");
            }
            else
            {
                printf("Queue is not empty .\n");
            }
            break;
        case 5:
            if (isQueueFull(&q1))
            {
                printf("Queue is full .\n");
            }
            else
            {
                printf("Queue is not full .\n");
            }
            break;
        case 6:
            system("cls");
        default:
            printf("wrong input.\n");
            break;
        }

    } while (option != 0);

    return 0;
}