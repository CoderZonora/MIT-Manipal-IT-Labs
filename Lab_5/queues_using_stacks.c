#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_SIZE 100
typedef struct{
    int top;
    int items[MAX_SIZE];
}Stack;

typedef struct{
    Stack stack1;
    Stack stack2;
    }Queue;

void initStack(Stack *s){
    s->top = -1;
    }
int isStackEmpty(Stack *s) {
    return s->top == -1;
}
int isStackFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}
void push(Stack *s, int value) {
    if (isStackFull(s)) {
        printf("Stack is full\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}
int pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->items[(s->top)--];
}
int peek(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->items[s->top];
}
void initQueue(Queue *q) {
    initStack(&q->stack1);
    initStack(&q->stack2);
}
int isQueueEmpty(Queue *q) {
    return isStackEmpty(&q->stack1) && isStackEmpty(&q->stack2);
}
void enqueue(Queue *q,int value){
push(&q->stack1, value);
}
int dequeue(Queue *q) {
    if (isStackEmpty(&q->stack2)) {
        while (!isStackEmpty(&q->stack1)) {
            push(&q->stack2, pop(&q->stack1));
        }
    }
    if(isStackEmpty(&q->stack2)) {
        printf("Queue is empty\n");
        exit(1);
    }
    return pop(&q->stack2);
}
int main(){
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
return 0;
}
