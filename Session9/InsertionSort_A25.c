#include<stdio.h>

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<n;i++){
        int key =a[i];
        int j;
        for( j=i-1;(j>=0 && key<a[j]);j--){
            a[j+1]=a[j];
        }
        a[j+1]=key;
    }
    printf("\nArray after sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}