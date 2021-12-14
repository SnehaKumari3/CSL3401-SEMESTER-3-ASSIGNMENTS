#include <stdio.h>

int partition(int a[], int s, int e)
{
    int pivot = a[s];
    int left = s, right = e;
    while (left < right)
    {
        while (left < e && a[left] <= pivot)
        {
            left++;
        }
        while (right > s && a[right] > pivot)
        {
            right--;
        }

        if (left < right)
        {
            //swap a[left] and a[right]
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
    }
    //swap pivot and a[right]
    int temp = a[s];
    a[s] = a[right];
    a[right] = temp;
    return right;
}

void QuickSort(int a[], int s, int e)
{
    if (s < e)
    {
        int p = partition(a, s, e);
        QuickSort(a, 0, p - 1);
        QuickSort(a, p + 1, e);
    }
}

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    QuickSort(a, 0, n - 1);
    printf("Displaying the array after sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}