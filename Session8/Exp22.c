#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int front1;
    int rear1;
    int front2;
    int rear2;
    int *Q;
};
void createQueue(struct Queue *q)
{
    q->size = 5;
    q->Q = (int *)malloc(q->size * sizeof(int));
    q->front1 = -1;
    q->rear1 = -1;
    q->front2 = q->size;
    q->rear2 = q->size;
}

void enqueue(struct Queue *q, int data)
{
    if (q->rear1 == q->rear2 - 1)
    {
        printf("Queue is full , can't perform enqueue.\n");
    }
    else if (q->rear1 == -1)
    {
        q->front1 = 0;
        q->rear1 = 0;
        q->Q[q->rear1] = data;
        printf("Element enqueued at 1st position.\n");
    }
    else
    {
        q->rear1++;
        q->Q[q->rear1] = data;
        printf("Element enqueued .\n");
    }
}

void inject(struct Queue *q, int data)
{
    if (q->rear1 == q->rear2 - 1)
    {
        printf("Queue is full , can't perform injection.\n");
    }
    else if (q->rear2 == q->size)
    {
        q->front2 = q->size - 1;
        q->rear2 = q->size - 1;
        q->Q[q->rear2] = data;
        printf("Element enqueued at last position.\n");
    }
    else
    {
        q->rear2--;
        q->Q[q->rear2] = data;
        printf("Element injected.\n");
    }
}

void dequeue(struct Queue *q)
{
    int x;
    if (q->front1 == -1)
    {
        printf("Queue is empty , Nothing to dequeue!\n");
    }
    else
    {
        x = q->Q[q->front1];
        printf("deleted element is %d\n", x);
        if (q->rear1 == q->front1)
        {
            q->front1 = -1;
            q->rear1 = -1;
        }
        else
        {
            q->front1++;
        }
    }
}

void eject(struct Queue *q)
{
    int x;
    if (q->front2 == q->size)
    {
        printf("Queue is empty , Nothing to eject!\n");
    }
    else
    {
        x = q->Q[q->front2];
        printf("deleted element is %d\n", x);
        if (q->rear2 == q->front2)
        {
            q->front2 = q->size;
            q->rear2 = q->size;
        }
        else
        {
            q->front2--;
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
        printf("1. enqueue() , 2. dequeue() , 3. inject() , 4. eject() , 5. clearscreen()\n");
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
            printf("enter the element you want to inject: ");
            scanf("%d", &value);
            inject(&q1, value);
            break;
        case 4:
            eject(&q1);
            break;
        case 5:
            system("cls");
        default:
            printf("wrong input.\n");
            break;
        }

    } while (option != 0);

    return 0;
}