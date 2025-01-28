#include<stdio.h>
int main(){
int a[20][30],b[20][30],m,n,p,q;
printf("Enter the rows and columns of matrix a:");
scanf("%d %d",&m,&n);
printf("Enter the rows and columns of matrix b:");
scanf("%d %d",&p,&q);
int c[100][100];
int d[100][100]
printf("Addition of the matrices: ");
if(m==p && n==q){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            c[i][j] = a[i][j]+b[i][j];
        }
    }
    for(int i = 0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d \t",c[i][j]);
        }
        printf("\n");
    }
    printf("Multiplication of the matrices: ");
    if(n==p){
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                c[i][j] = 0;
                for(int k=0;k<n;k++){
                    c[i][j] += a[i][k]*b[k][i];
                }
            }
        }
    }
return 0;
}
}
