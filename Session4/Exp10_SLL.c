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

void insert_End(int x)
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
            printf("node inserted at beggining.\n");
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
        }
        printf("Node created.\n");
    }
}

void insert_Beginning(int x)
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
            printf("node inserted at beggining.\n");
        }
        else
        {
            new_node->next = head;
            head = new_node;
            printf("Node created.\n");
        }
    }
}

void insert_After_Node(int key, int x)
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
            printf("List Is Empty , Insertion is not possible.\n");
        }
        else
        {
            SLL *temp;
            temp = head;
            while (temp->next != NULL && temp->data != key)
            {
                temp = temp->next;
            }

            if (temp != NULL)
            {
                new_node->next = temp->next;
                temp->next = new_node;
                printf("Node created.\n");
            }
            else
            {
                printf("Element not found!.\n");
            }
        }
    }
}

void deleteNode(int n)
{
    if (isEmpty())
    {
        printf("List is empty , nothing to delete\n");
    }
    else
    {
        SLL *temp = head;
        SLL *prev;
        prev = temp;
        int x = -1;
        while (temp != NULL)
        {
            if (temp->data == n)
            {
                if (temp == head)
                {
                    x = temp->data;
                    head = temp->next;
                    printf("node deleted (deleted element : %d )\n", x);
                }
                else
                {
                    x = temp->data;
                    prev->next = temp->next;
                    printf("node deleted (deleted element : %d )\n", x);
                }
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        if (x == -1)
            printf("node not found\n");
    }
}

void displayList()
{
    if (isEmpty())
    {
        printf("List is empty , nothing to display\n");
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
    int value, option, key;

    do
    {

        printf("\nSelect the opertaion you want to perform. Enter 0 to exit.\n");
        printf("1.insert_End() ");
        printf("2.insert_Beginning() ");
        printf("3.insert_After_Node() ");
        printf("4.isEmpty() ");
        printf("5.deleteNode() ");
        printf("6.displayList()");
        printf("7.clearscreen()\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            break;
        case 1:
            printf("enter the element you want to add to list: ");
            scanf("%d", &value);
            insert_End(value);
            break;
        case 2:
            printf("enter the element you want to add to list: ");
            scanf("%d", &value);
            insert_Beginning(value);
            break;
        case 3:
            printf("enter the element you want to add to list: ");
            scanf("%d", &value);

            printf("enter the element after which you want to add in the list: ");
            scanf("%d", &key);
            insert_After_Node(key, value);
            break;
        case 4:
            if (isEmpty())
            {
                printf("List is empty .\n");
            }
            else
            {
                printf("List is not empty .\n");
            }
            break;
        case 5:
            printf("enter the element you want to delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;
        case 6:
            displayList();
            break;
        case 7:
            system("cls");
        default:
            printf("wrong input.\n");
            break;
        }

    } while (option != 0);

    return 0;
}