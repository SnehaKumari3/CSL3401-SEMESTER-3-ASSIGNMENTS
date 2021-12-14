#include <stdio.h>

int LinearSearch(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key == a[i])
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements of the array :", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int key, temp;
    printf("Enter the element you want to searh: ");
    scanf("%d", &key);
    temp = LinearSearch(a, n, key);
    if (temp == -1)
    {
        printf("Unsuccessful! element not found");
    }
    else
    {
        printf("Successful! elment is found at index position %d .", temp);
    }
    return 0;
}