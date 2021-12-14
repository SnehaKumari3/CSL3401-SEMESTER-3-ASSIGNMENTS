#include <stdio.h>
#include <string.h>
#define size 10
int stack[size];
int top = -1;

char pop()
{
    if (top == -1)
        printf("\n stack is underflow");
    else
        return stack[top--];
}
void push(char ch)
{
    if (top == size - 1)
    {
        printf("stack overflow\n");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

int isDigit(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isAlphabet(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void main()
{
    char postfix[20];
    int val, opr1, opr2;
    printf("\nEnter a postfix expression: ");
    gets(postfix);
    //evaluation of the postfix expression
    for (int i = 0; postfix[i] != '\0'; i++)
    {

        if (isDigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else if (isAlphabet(postfix[i]))
        {
            printf("\nEnter the value of %c: ", postfix[i]);
            scanf("%d", &val);
            push(val);
        }
        else
        {
            opr2 = pop();
            opr1 = pop();
            switch (postfix[i])
            {
            case '+':
                push(opr1 + opr2);
                break;
            case '-':
                push(opr1 - opr2);
                break;
            case '*':
                push(opr1 * opr2);
                break;
            case '/':
                push(opr1 / opr2);
                break;
            case '%':
                push(opr1 % opr2);
                break;
            default:
                printf("\ninvalid operation");
            }
        }
    }
    printf("\nAfter Evaluation of the postfix expression, value is : %d", stack[top]);
}
