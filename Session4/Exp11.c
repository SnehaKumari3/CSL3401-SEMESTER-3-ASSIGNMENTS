#include <stdio.h>
#include <stdlib.h>
typedef struct Node SLL;
struct Node
{
    int data;
    SLL *next;

} *head = NULL;

int isEmpty()
{
    if (head == NULL)
        return 1;
    else
    {
        return 0;
    }
}

void push(int x)
{
    SLL *new_node;
    new_node = (SLL *)malloc(sizeof(SLL));
    if (new_node == NULL)
    {
        printf("NO Memory available.\n");
    }
    else
    {
        new_node->data = x;
        new_node->next = NULL;
        if (isEmpty())
        {
            head = new_node;
            printf("first element pushed.\n");
        }
        else
        {
            SLL *temp;
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            printf("element pushed.\n");
        }
    }
}

void pop()
{
    if (isEmpty())
    {
        printf("Stack is empty , nothing to pop\n");
    }
    else if (head->next == NULL)
    {
        printf("popped element is %d.\n", head->data);
        head = NULL;
    }
    else
    {
        SLL *temp = head;
        SLL *prev;
        prev = temp;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        printf("popped element is %d.\n", temp->data);
        prev->next = NULL;
    }
}

void displayStack()
{
    if (isEmpty())
    {
        printf("Stack is empty , nothing to display\n");
    }
    else
    {
        SLL *temp = head;
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

        printf("\nSelect the opertaion you want to perform. Enter 0 to exit.\n");

        printf("1.push() ");
        printf("2.pop() ");
        printf("3.displayList() ");
        printf("4.isEmpty() ");
        printf("5.clearscreen()\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            break;
        case 1:
            printf("enter the element you want to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            displayStack();
            break;
        case 4:
            if (isEmpty())
            {
                printf("Stack is empty .\n");
            }
            else
            {
                printf("Stack is not empty .\n");
            }
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
