#include <stdio.h>

void Merge(int a[], int l, int m, int r)
{
    int temp[10];
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= m)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <= r)
    {
        temp[k] = a[j];
        k++;
        j++;
    }

    for (int p = l; p <= r; p++)
    {
        a[p] = temp[p];
    }
}
void MergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);
        Merge(a, l, m, r);
    }
}
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    MergeSort(a, 0, n - 1);
    printf("Displaying the array after sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}