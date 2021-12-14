#include <stdio.h>

int main(){
    int a[10],sum=0;
    printf("Enter 10 element: ");
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<10;i++){
        int r;
        r=a[i]/10;
        r=r%10;
        if(r%5==0){
            sum=sum+a[i];
        }
    }
    printf("sum is %d",sum);

    return 0;
}