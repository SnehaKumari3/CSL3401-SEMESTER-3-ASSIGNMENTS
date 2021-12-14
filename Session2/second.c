#include <stdio.h>

int main()
{
    int n;
    printf("enter n: ");
    scanf("%d", &n);
    int a[n];
    printf("enter n elment: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int max = a[0], j = 0, c = 0;
    while (n >= 0)
    {
        max = a[0],j=0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > max)
            {
                max = a[i];
                j = i;
            }
            else
            {
                continue;
            }
        }
        c++;
        n = j ;
    }
    printf("%d", c);
    return 0;
}