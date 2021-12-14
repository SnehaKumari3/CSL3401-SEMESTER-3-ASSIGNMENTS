#include <stdio.h>
#include<stdlib.h>
int main(){

    int n;
    printf("Enter the size of list: ");
    scanf("%d",&n);
    int *a;
    a=(int *) malloc(n*sizeof(int));
    printf("Enter %d element of the list: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int min=a[0],max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
        else if(a[i]<min){
            min=a[i];
        }
    }
    printf("The minimum element is %d and maximum is %d .",min,max);
    
    return 0;
}