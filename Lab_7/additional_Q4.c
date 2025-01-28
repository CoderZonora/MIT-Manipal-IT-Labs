#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;

};

struct Stack{
    struct Node* top;
};

struct Stack* createStack(){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
};

int isEmpty(struct Stack* stack) {
return stack->top == NULL;
}

void push(struct Stack* stack,int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    }
