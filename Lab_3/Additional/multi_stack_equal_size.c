#include <stdio.h>

#define MAX_SIZE 100  // Maximum size of the main array

// Structure to define multiple stacks in an array
typedef struct {
    int arr[MAX_SIZE];   // Main array to hold elements of all stacks
    int top[10];         // Array to keep track of the top of each stack (assuming a maximum of 10 stacks)
    int stackSize;       // Size of each stack
    int numStacks;       // Total number of stacks
} MultiStack;

// Initialize the multiple stack structure
void initializeMultiStack(MultiStack *ms, int m, int n) {
    ms->stackSize = m / n;
    ms->numStacks = n;

    // Initialize all tops of stacks to -1 (indicating empty)
    for (int i = 0; i < n; i++) {
        ms->top[i] = -1;
    }
}

// Push operation for a specific stack
void push(MultiStack *ms, int stackNum, int value) {
    if (stackNum < 0 || stackNum >= ms->numStacks) {
        printf("Invalid stack number!\n");
        return;
    }

    // Calculate the top position for the stack
    if (ms->top[stackNum] >= ms->stackSize - 1) {
        printf("Stack %d is full!\n", stackNum);
        return;
    }

    // Increment the top index and insert the value
    ms->top[stackNum]++;
    ms->arr[stackNum * ms->stackSize + ms->top[stackNum]] = value;
    printf("Pushed %d into stack %d\n", value, stackNum);
}

// Pop operation for a specific stack
void pop(MultiStack *ms, int stackNum) {
    if (stackNum < 0 || stackNum >= ms->numStacks) {
        printf("Invalid stack number!\n");
        return;
    }

    // Check if the stack is empty
    if (ms->top[stackNum] == -1) {
        printf("Stack %d is empty!\n", stackNum);
        return;
    }

    // Retrieve the value and decrement the top index
    int value = ms->arr[stackNum * ms->stackSize + ms->top[stackNum]];
    ms->top[stackNum]--;
    printf("Popped %d from stack %d\n", value, stackNum);
}

// Display a specific stack
void displayStack(MultiStack *ms, int stackNum) {
    if (stackNum < 0 || stackNum >= ms->numStacks) {
        printf("Invalid stack number!\n");
        return;
    }

    // Check if the stack is empty
    if (ms->top[stackNum] == -1) {
        printf("Stack %d is empty!\n", stackNum);
        return;
    }

    // Print the elements of the stack
    printf("Stack %d elements: ", stackNum);
    for (int i = 0; i <= ms->top[stackNum]; i++) {
        printf("%d ", ms->arr[stackNum * ms->stackSize + i]);
    }
    printf("\n");
}

// Main function
int main() {
    MultiStack ms;
    int m, n;
    
    // Input the size of the array and the number of stacks
    printf("Enter the total size of the array (m): ");
    scanf("%d", &m);
    printf("Enter the number of stacks (n): ");
    scanf("%d", &n);
    
    if (m % n != 0 || n > 10) {
        printf("Invalid input: 'm' should be divisible by 'n' and 'n' should be <= 10.\n");
        return 1;
    }
    
    // Initialize the multi-stack structure
    initializeMultiStack(&ms, m, n);

    // Example usage
    push(&ms, 0, 10);
    push(&ms, 0, 20);
    push(&ms, 1, 30);
    push(&ms, 2, 40);
    pop(&ms, 0);
    displayStack(&ms, 0);
    displayStack(&ms, 1);
    displayStack(&ms, 2);

    return 0;
}
