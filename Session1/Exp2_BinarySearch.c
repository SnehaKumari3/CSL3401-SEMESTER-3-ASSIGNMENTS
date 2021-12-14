#include <stdio.h>

int BinarySearch(int a[], int n, int key)
{
    int first = 0, last = n - 1;
    int mid;
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (key == a[mid])
        {
            return mid;
        }
        else if (a[key] < a[mid])
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d element of the array: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int key, temp;
    printf("Enter the element you want to searh: ");
    scanf("%d", &key);
    temp = BinarySearch(a, n, key);
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