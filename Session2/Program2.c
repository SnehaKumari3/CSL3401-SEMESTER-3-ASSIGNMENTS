#include <stdio.h>
#include<stdlib.h>
int main(){

    int n,pos,value;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *a;
    a=(int *) malloc(n*sizeof(int));
    printf("Enter %d element of the array: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
     printf("Enter the position at which you want to insert: ");
     scanf("%d",&pos);
     if(pos<=n){
        printf("Enter the value you want to insert: ");
        scanf("%d",&value);
        for(int i=n-1;i>=(pos-1);i--){
            a[i+1]=a[i];
        }
        
        a[pos-1]=value;
        n++;
        printf("Array after insertion:\n");
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }

     }
     else{
         printf("Position not found in the array.");
     }
     
     printf("\nEnter the position at which you want to delete: ");
     scanf("%d",&pos);
     if(pos<=n){
         for(int i=pos-1;i<n-1;i++){
         a[i]=a[i+1];
         }
         n--;
        printf("Array after deletion:\n");
         for(int i=0;i<n;i++){
             printf("%d ",a[i]);
         }
     }
     else{
         printf("Position not found in the array.");
     }
     
    
    return 0;
}