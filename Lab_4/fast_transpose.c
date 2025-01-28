#include<stdio.h>
#define MAX 100

typedef struct{
    int row;
    int col;
    int value;
}Mat;


void fastTranspose(Mat input[],int ele,Mat output[],int*eleOut){
    int rowSize[MAX] = {0};
    int sPos[MAX];

    for(int i=0;i<MAX;i++){
        sPos[i] = 0;
    }
    for (int i = 0; i < ele; i++) {
        rowSize[input[i].col]++;
    }
    sPos[0] = 0;
    for (int i = 1; i < MAX; i++) {
        sPos[i] = sPos[i - 1] + rowSize[i - 1];
    }

    for (int i = 0; i < ele; i++) {
        int row = input[i].col;
        int col = input[i].row;
        int pos = sPos[row]++;
        output[pos].row = row;
        output[pos].col = col;
        output[pos].value = input[i].value;
    }
    *eleOut = ele;
}

void printSparseMatrix(Mat arr[],int ele){
    printf("Row  Column  Value\n");
    for (int i = 0; i < ele; i++) {
        printf("%d    %d       %d\n", arr[i].row, arr[i].col, arr[i].value);
    }
}

int main(){
    Mat input[] = {
         {11, 22, 0},
        {0, 33, 44},
        {0, 0, 55},
        {0, 0, 0},
        {0, 0, 0}
    };
     int ele = 5;
    Mat output[MAX];
    int eleOut;
    fastTranspose(input, ele, output, &eleOut);
    printf("Original Sparse Matrix:\n");
    printSparseMatrix(input, ele);
    printf("\nTransposed Sparse Matrix:\n");
    printSparseMatrix(output, eleOut);
return 0;}
