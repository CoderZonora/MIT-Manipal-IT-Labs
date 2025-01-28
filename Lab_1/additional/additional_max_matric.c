#include<stdio.h>
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}
int main(){
    int rows,cols;
    printf("Enter rows and cols: ");
    scanf("%d %d",&rows,&cols);
    int a[rows][cols],b[rows][cols],c[rows][cols];
    printf("Enter for matrix A: ");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter for matrix B: ");
        for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            scanf("%d",&b[i][j]);
        }
    }
        for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            c[i][j] = max(a[i][j],b[i][j]);
        }
    }
        printf("C matrix: ");
        for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d",c[i][j]);
        }
    }
return 0;}
