#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *S;
};
void Stack(struct Stack *st)
{
    printf("Enter the size of Stack: ");
    scanf("%d", &st->size);
    st->S = (int *)malloc(st->size * sizeof(int));
    st->top = -1;
}
int isStackEmpty(struct Stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isStackFull(struct Stack *st)
{
    if (st->top == (st->size - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct Stack *st, int data)
{
    if (isStackFull(st))
    {
        printf("Stack is full , can't push.\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = data;
        printf("Element is pushed into the stack.\n");
    }
}
int pop(struct Stack *st)
{
    int x = -1;
    if (isStackEmpty(st))
    {
        printf("Stack underflow , Nothing to pop out!\n");
    }
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}
void displayStack(struct Stack st)
{
    if (isStackEmpty(&st))
    {
        printf("Stack is Empty , Nothing to display !\n");
    }
    else
    {
        printf("Displaying the elements of stack: \n");
        for (int i = 0; i <= st.top; i++)
        {
            printf("%d  ", st.S[i]);
        }
        printf("\n");
    }
}

int main()
{
    int value, option;
    struct Stack s1;
    Stack(&s1);
    do
    {

        printf("\nSelect the opertaion you want to perform. Enter 0 to exit.\n ");
        printf("1.push()  2.pop()  3.displayStack() 4.clearscreen()\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            break;
        case 1:
            printf("enter the element you want to push: ");
            scanf("%d", &value);
            push(&s1, value);
            break;
        case 2:
            printf("popped element is %d\n", pop(&s1));
            break;
        case 3:
            displayStack(s1);
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
