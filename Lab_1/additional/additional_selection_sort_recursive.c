#include <stdio.h>

void recursiveSelectionSort(int arr[], int start, int end);
void swap(int *x, int *y);
void printArray(int arr[], int size);

void recursiveSelectionSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int minIndex = start;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    swap(&arr[start], &arr[minIndex]);
    recursiveSelectionSort(arr, start + 1, end);
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array:\n");
    printArray(arr, size);
    recursiveSelectionSort(arr, 0, size - 1);
    printf("Sorted array:\n");
    printArray(arr, size);
    return 0;
}


