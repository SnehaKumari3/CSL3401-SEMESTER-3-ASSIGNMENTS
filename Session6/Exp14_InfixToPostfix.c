#include <stdio.h>
#include <string.h>
#define size 10
char stack[size];
int top = -1;

int pre(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/' || ch == '%')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
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

void main()
{
    char infix[20], postfix[20];
    int j = 0;
    printf("\nEnter an infix expression: ");
    gets(infix);
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= '0' && infix[i] <= '9'))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while (top > -1 && (pre(stack[top]) >= pre(infix[i])))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (top > -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("After Conversion , the postfix expression is : %s", postfix);
}
