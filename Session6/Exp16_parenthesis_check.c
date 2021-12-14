#include <stdio.h>
#include <string.h>
#define size 20
char stack[size];
int top = -1;

int isStackEmpty()
{
    if (top == -1)
    {
        return 1;
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

int isValid(char exp[])
{

    int ans = 1;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (!(isStackEmpty()) && stack[top] == '(')
            {
                pop();
            }
            else
            {
                ans = 0;
                return ans;
            }
        }
        else if (exp[i] == '}')
        {
            if (!(isStackEmpty()) && stack[top] == '{')
            {
                pop();
            }
            else
            {
                ans = 0;
                return ans;
            }
        }
        else if (exp[i] == ']')
        {
            if (!(isStackEmpty()) && stack[top] == '[')
            {
                pop();
            }
            else
            {
                ans = 0;
                return ans;
            }
        }
    }

    if (isStackEmpty)
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
    char exp[20];
    printf("\nEnter an expression: ");
    gets(exp);

    if (isValid(exp))
    {
        printf("Balanced Expression\n");
    }
    else
    {
        printf("Unalanced Expression\n");
    }
}