#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int Top1;
    int Top2;
    int *S;
};
void createStack(struct Stack *s)
{
    s->size = 5;
    s->S = (int *)malloc(s->size * sizeof(int));
    s->Top1 = -1;
    s->Top2 = s->size;
}

void Push1(struct Stack *s, int data)
{
    if (s->Top1 == s->Top2- 1)
    {
        printf("stack is full , can't perform push operation.\n");
    }
    else if (s->Top1 == -1)
    {
        s->Top1=0;
        s->S[s->Top1]=data;
        printf("Element pushed at 1st position.\n");
    }
    else
    {
        s->Top1++;
        s->S[s->Top1]=data;
        printf("Element pushed .\n");
    }
}

void Push2(struct Stack *s, int data)
{
    if (s->Top1 == s->Top2- 1)
    {
        printf("stack is full , can't perform push operation.\n");
    }
    else if (s->Top2 == s->size)
    {
        s->Top2 = s->size - 1;
        s->S[s->Top2] = data;
        printf("Element pushed at last position.\n");
    }
    else
    {
        s->Top2--;
        s->S[s->Top2]=data;
        printf("Element pushed .\n");
    }
}

int Pop1(struct Stack *s)
{
    int x;
    if (s->Top1 == -1)
    {
        printf("Stack is empty , Nothing to delete!\n");
    }
    else
    {
        x = s->S[s->Top1];
        s->Top1--;
    }
    return x;
}

int Pop2(struct Stack *s)
{
    int x;
    if (s->Top2 == s->size-1)
    {
        printf("Stack is empty , Nothing to delete!\n");
    }
    else
    {
        x = s->S[s->Top2];
        s->Top2++;
    }
    return x;
}

int main()
{
    int value, option;
    struct Stack s1;
    createStack(&s1);
    do
    {
        printf("\nSelect the opertaion you want to perform. Enter 0 to exit.\n");
        printf("1. Push1() , 2. Push2() , 3. Pop1() , 4. Pop2() , 5. clearscreen()\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            break;
        case 1:
            printf("enter the element you want to push into stack1: ");
            scanf("%d", &value);
            Push1(&s1, value);
            break;
        case 2:
            printf("enter the element you want to push into stack2: ");
            scanf("%d", &value);
            Push2(&s1, value);
            break;
        case 3:
            value=Pop1(&s1);
            if(value==-1){
                printf("Stack is empty , Nothing to delete!\n");
            }
            else{
                printf("Popped value from stack1 is %d \n",value);
            }
            break;
        case 4:
            value=Pop2(&s1);
            if(value==-1){
                printf("Stack is empty , Nothing to delete!\n");
            }
            else{
                printf("Popped value from stack2 is %d \n",value);
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