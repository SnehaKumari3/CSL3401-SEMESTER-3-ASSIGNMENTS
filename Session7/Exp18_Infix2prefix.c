#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 10
char stack[SIZE];
int top = -1;

void push(char c)
{
  if (top >= SIZE - 1)
    printf("\n Stack Overflow.");
  else
  {
    top++;
    stack[top] = c;
  }
}

char pop()
{
  char c;
  c = '\0';
  if (top < 0)
    printf("\n Stack Underflow.");
  else
  {
    c = stack[top];
    top--;
  }
  return c;
}

int isoperator(char s)
{
  if (s == '^' || s == '*' || s == '/' || s == '+' || s == '-')
    return 1;
  else
    return 0;
}

int precedence(char s)
{
  if (s == '^')
    return 5;
  else if (s == '/')
    return 4;
  else if (s == '*')
    return 3;
  else if (s == '+')
    return 2;
  else if (s == '-')
    return 1;
  else
    return 0;
}

void InfixToPrefix(char infix[], char prefix[])
{
  int i, j, k, pos, l;
  char item, x, reverse[SIZE];

  pos = 0;
  l = strlen(infix);
  //reversing infix expression
  for (k = l - 1; k >= 0; k--)
  {
    reverse[pos] = infix[k];
    pos++;
  }
  reverse[pos] = '\0';
  strcpy(infix, reverse);
  //swap '(' to ')' & ')' to '('

  for (i = 0; infix[i] != '\0'; i++)
  {
    if (infix[i] == ')')
      infix[i] = '(';
    else if (infix[i] == '(')
      infix[i] = ')';
  }
  push('(');

  strcat(infix, ")");
  i = 0;
  j = 0;

  item = infix[i];

  while (item != '\0')
  {
    if (item == '(')
    {
      push(item);
    }
    else if (isdigit(item) || isalpha(item))
    {

      prefix[j] = item;
      j++;
    }
    else if (isoperator(item) == 1)
    {

      x = pop();
      while (isoperator(x) == 1 && precedence(x) >= precedence(item))
      {
        prefix[j] = x;
        j++;
        x = pop();
      }

      push(x);

      push(item);
    }

    else if (item == ')')
    {
      x = pop();
      while (x != '(')
      {
        prefix[j] = x;
        j++;
        x = pop();
      }
    }
    else
    {
      printf("\nInvalid infix Expression.\n");
      break;
    }
    i++;

    item = infix[i];
  }
  if (top > 0)
    printf("\nInvalid infix Expression.");
  prefix[j] = '\0';
  pos = 0;
  l = strlen(prefix);
  for (k = l - 1; k >= 0; k--)
  {
    reverse[pos] = prefix[k];
    pos++;
  }
  reverse[pos] = '\0';
  strcpy(prefix, reverse);
}

int main()
{
  char infix[SIZE], prefix[SIZE];
  printf("\nEnter an infix expression : ");
  gets(infix);
  InfixToPrefix(infix, prefix);
  printf("\nPrefix Expression of this infix expression : ");
  puts(prefix);
  return 0;
}
