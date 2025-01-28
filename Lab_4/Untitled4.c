
#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Triple;

void fastTranspose(Triple input[], int numElements, Triple output[], int *numElementsOut) {
    int rowSize[MAX] = {0};
    int startPos[MAX];

    for (int i = 0; i < MAX; i++) {
        startPos[i] = 0; //Initialize all startpositions to 0 for all.
    }

    for (int i = 0; i < numElements; i++) {
        rowSize[input[i].col]++;
    }

    startPos[0] = 0;
    for (int i = 1; i < MAX; i++) {
        startPos[i] = startPos[i - 1] + rowSize[i - 1];
    }

    for (int i = 0; i < numElements; i++) {
        int row = input[i].col;
        int col = input[i].row;
        int pos = startPos[row]++;
        output[pos].row = row;
        output[pos].col = col;
        output[pos].value = input[i].value;
    }

    *numElementsOut = numElements;
}

void printSparseMatrix(Triple arr[], int numElements) {
    printf("Row  Column  Value\n");
    for (int i = 0; i < numElements; i++) {
        printf("%d    %d       %d\n", arr[i].row, arr[i].col, arr[i].value);
    }
}

int main() {
    Triple input[] = {
        {0, 1, 5},
        {1, 0, 8},
        {1, 2, 6},
        {2, 1, 9},
        {3, 0, 4}
    };
    int numElements = 5;
    Triple output[MAX];
    int numElementsOut;
    fastTranspose(input, numElements, output, &numElementsOut);
    printf("Original Sparse Matrix:\n");
    printSparseMatrix(input, numElements);
    printf("\nTransposed Sparse Matrix:\n");
    printSparseMatrix(output, numElementsOut);
    return 0;
}
