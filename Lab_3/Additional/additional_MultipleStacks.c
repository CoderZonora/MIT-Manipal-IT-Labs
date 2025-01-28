#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define NUM_STACKS 3

typedef struct {
    int top;
    int start;
    int capacity;
} Stack;

typedef struct {
    int data[MAX_SIZE];
    Stack stacks[NUM_STACKS];
} MultiStack;


void initMultiStack(MultiStack *ms, int capacities[]) {
    int startIndex = 0;
    for (int i = 0; i < NUM_STACKS; i++) {
        ms->stacks[i].start = startIndex;
        ms->stacks[i].capacity = capacities[i];
        ms->stacks[i].top = startIndex - 1;
        startIndex += capacities[i];
    }
}


int isStackEmpty(MultiStack *ms, int stackNum) {
    return ms->stacks[stackNum].top < ms->stacks[stackNum].start;
}

int isStackFull(MultiStack *ms, int stackNum) {
    return ms->stacks[stackNum].top >= (ms->stacks[stackNum].start + ms->stacks[stackNum].capacity - 1);
}

void push(MultiStack *ms, int stackNum, int value) {
    if (isStackFull(ms, stackNum)) {
        printf("Stack %d is full. Cannot push %d\n", stackNum, value);
        return;
    }
    ms->stacks[stackNum].top++;
    ms->data[ms->stacks[stackNum].top] = value;
}


int pop(MultiStack *ms, int stackNum) {
    if (isStackEmpty(ms, stackNum)) {
        printf("Stack %d is empty. Cannot pop\n", stackNum);
        return -1;
    }
    int value = ms->data[ms->stacks[stackNum].top];
    ms->stacks[stackNum].top--;
    return value;
}


int peek(MultiStack *ms, int stackNum) {
    if (isStackEmpty(ms, stackNum)) {
        printf("Stack %d is empty. Cannot peek\n", stackNum);
        return -1;
    }
    return ms->data[ms->stacks[stackNum].top];
}


void displayStack(MultiStack *ms, int stackNum) {
    if (isStackEmpty(ms, stackNum)) {
        printf("Stack %d is empty\n", stackNum);
        return;
    }
    printf("Stack %d contents: ", stackNum);
    for (int i = ms->stacks[stackNum].start; i <= ms->stacks[stackNum].top; i++) {
        printf("%d ", ms->data[i]);
    }
    printf("\n");
}


int main() {
    MultiStack ms;
    int capacities[NUM_STACKS] = {10, 15, 20};
    initMultiStack(&ms, capacities);


    push(&ms, 0, 1);
    push(&ms, 0, 2);
    push(&ms, 1, 10);
    push(&ms, 1, 20);
    push(&ms, 2, 100);
    push(&ms, 2, 200);


    displayStack(&ms, 0);
    displayStack(&ms, 1);
    displayStack(&ms, 2);

    printf("Popped from stack 0: %d\n", pop(&ms, 0));
    printf("Popped from stack 1: %d\n", pop(&ms, 1));
    printf("Popped from stack 2: %d\n", pop(&ms, 2));

    displayStack(&ms, 0);
    displayStack(&ms, 1);
    displayStack(&ms, 2);

    return 0;
}
