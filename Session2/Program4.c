#include <stdio.h>
int main(){
    int m,n,p,q;
    printf("Enter the rows and column of 1st matrix respectively: ");
    scanf("%d %d",&m,&n);
    printf("Enter elements of %dx%d matrix\n",m,n);
    int m1[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        scanf("%d",&m1[i][j]);
    }
    }
    printf("Enter the rows and column of 2nd matrix respectively: ");
    scanf("%d %d",&p,&q);
    int m2[p][q];
    printf("Enter elements of %dx%d matrix\n",p,q);
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
        scanf("%d",&m2[i][j]);
    }
    }
    int m3[p][q];
    if((p==m)&&(q==n)){
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                m3[i][j]=m1[i][j]+m2[i][j];
            }
        }
        printf("Additin of matrix:\n");
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                 printf("%d ",m3[i][j]);
            }
        printf("\n");
        }
        //substraction of matrix
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                m3[i][j]=m1[i][j]-m2[i][j];
            }
        }
        printf("Substraction of matrix:\n");
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                 printf("%d ",m3[i][j]);
            }
        printf("\n");
        }
    }
    else{
        printf("addition and substraction of these two matrix is not possible.\n");
    }

    if(n==p){
        for(int i=0;i<p;i++){
            for(int j=0;j<q;j++){
                m3[i][j]=0;
                for(int k=0;k<q;k++){
                    m3[i][j]+=m1[i][k]*m2[k][j];  
                }
            }
        }
        printf("multiplication of matrix:\n");
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                 printf("%d ",m3[i][j]);
            }
        printf("\n");
        }
    }
    else{
        printf("multiplication of these two matrix is not possible.\n");
    }
    return 0;
}