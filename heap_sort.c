#include <stdio.h>

// Function to build a max heap from an array
void build_max_heap(int arr[], int n) {
    for (int i = 2; i <= n; i++) {
        int current = i;
        int parent = current / 2;
        int item = arr[current];

        // Percolate up to maintain the max-heap property
        while (parent > 0 && item > arr[parent]) {
            arr[current] = arr[parent];
            current = parent;
            parent = current / 2;
        }
        arr[current] = item;
    }
}

// Function to adjust the max heap after removing the root
void heapify_down(int arr[], int n) {
    int root = 1;
    int largest = root;
    int left_child, right_child;
    int item = arr[root];

    while (2 * root <= n) {  // While the root has at least one child
        left_child = 2 * root;
        right_child = left_child + 1;

        // Find the largest among root and its children
        if (left_child <= n && arr[left_child] > arr[largest]) {
            largest = left_child;
        }
        if (right_child <= n && arr[right_child] > arr[largest]) {
            largest = right_child;
        }

        // If the root is already the largest, break
        if (largest == root) {
            break;
        }

        // Swap the largest child with the root
        arr[root] = arr[largest];
        root = largest;  // Move to the largest child's index
    }

    // Place the original root item in its correct position
    arr[root] = item;
}

// Function to perform heap sort
void heap_sort(int arr[], int n) {
    // Step 1: Build the initial max heap
    build_max_heap(arr, n);

    // Step 2: Sort the array
    for (int i = n; i >= 2; i--) {
        // Swap the max element (root) with the last element
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;

        // Restore the heap property for the remaining elements
        heapify_down(arr, i - 1);
    }
}

// Function to print an array
void print_array(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Array to hold the elements (1-indexed for convenience)
    int arr[n + 1];

    printf("Enter the elements:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform heap sort
    heap_sort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}
