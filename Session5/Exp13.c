#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *next;
};

void reverse(struct node **head, int n)
{
    struct node *p, *q, *r, *rear;

    p = q = r = *head;
    if (n == 0)
    {
        q = q->next;
        p->next = q->next;
        q->next = p;
        *head = q;
    }
    else
    {
        p = p->next->next;
        q = q->next;
        r->next = NULL;
        rear = r;
        q->next = r;

        while (n > 0 && p != NULL)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
            n--;
        }
        *head = q;
        rear->next = p;
    }
}

void create(struct node **head)
{
    int c, ch;
    struct node *temp, *rear;

    do
    {
        printf("Enter your number: ");
        scanf("%d", &c);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = c;
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;
        printf("Press 1 to continue and 0 to exit: ");
        scanf("%d", &ch);
    } while (ch != 0);
    printf("\n");
}

void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d\t", p->num);
        p = p->next;
    }
    printf("\n");
}

void release(struct node **head)
{
    struct node *temp = *head;
    *head = (*head)->next;
    while ((*head) != NULL)
    {
        free(temp);
        temp = *head;
        (*head) = (*head)->next;
    }
}

int main()
{
    struct node *p = NULL;
    int n;

    printf("Enter data into the list\n");
    create(&p);
    printf("Displaying the nodes in the list:\n");
    display(p);
    printf("Enter the number N to reverse first N node: ");
    scanf("%d", &n);
    printf("Reversing the list...\n");
    if (n > 1)
    {
        reverse(&p, n - 2);
    }
    printf("Displaying the reversed list:\n");
    display(p);
    release(&p);

    return 0;
}
