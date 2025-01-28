#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct {
int row;
int col;
int value;
}SparseMat;

void printSparseMatrix(SparseMat *matrix, int ele){
for(int i=0;i<ele;i++){
    printf("Row: %d, Col: %d, Value: %d \n",matrix[i].row, matrix[i].col,matrix[i].value);
}
}

void transposeSparseMat(SparseMat *matrix, SparseMat *transposematrix, int ele){
    int index=0;
    for(int i=0;i<ele;i++){
        transposematrix[index].row = matrix[i].col;
        transposematrix[index].col = matrix[i].row;
        transposematrix[index].value = matrix[i].value;
        index++;
    }
}
int main(){
    SparseMat matrix[MAX];
    SparseMat transposematrix[MAX];

    int ele;

    printf("Enter the number of non-zero elements");
    scanf("%d",&ele);

    printf("Enter the elements (row column value)");
    for(int i=0;i<ele;i++){
        printf("Element %d: ", i+1);
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col,&matrix[i].value);

    }
    transposeSparseMat(matrix, transposematrix,ele);

    printf("\n Original Sparse Matrix: \n");
    printSparseMatrix(matrix,ele);
    printf("\n Transposed Sparse Matrix: \n");
    printSparseMatrix(transposematrix,ele);

return 0;}
