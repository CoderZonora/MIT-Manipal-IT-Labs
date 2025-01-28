#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    int items[MAX_STACK_SIZE];
} Stack;
void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
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

int evaluatePostfix(const char *expression) {
    Stack s;
    initStack(&s);

    while (*expression) {
        if (isdigit(*expression)) {
            push(&s, *expression - '0');
        } else {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            int result;

            switch (*expression) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                default:
                    printf("Invalid operator: %c\n", *expression);
                    exit(1);
            }
            push(&s, result);
        }
        expression++;
    }

    return pop(&s);
}

int main() {
    printf("Enter expression: \n");
    char c[10];
    scanf("%s",c);
    int result = evaluatePostfix(c);
    printf("Result of postfix expression '%s' is %d\n", c, result);
    return 0;
}
