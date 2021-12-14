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
    for(int i=0;i<n-1;i++){
        int min=i,key=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[key]){
                key=j;
            }
        }
        if(min!=key){
            int temp=a[min];
            a[min]=a[key];
            a[key]=temp;
        }
    }
    printf("\nArray after sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}