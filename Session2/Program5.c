#include <stdio.h>

int main(){
    int m, n,sum=0;
    printf("Enter the rows and column of matrix respectively: ");
    scanf("%d %d",&m,&n);
    if(m!=n){
        printf("Not a square matrix.");
    }
    else{
    int a[m][n];
    printf("Enter elements of %dx%d matrix\n",m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        scanf("%d",&a[i][j]);
    }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                sum+=a[i][j];
            }
            else if((i+j)==(m-1)){
                sum+=a[i][j];
            }

    }
    }
    printf("The sum of both diagonal elements of matrix is: %d",sum);
    }
    
    return 0;
}