#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, char value) {
    if (isStackFull(s)) {
        printf("Stack is full\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

char pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->items[s->top];
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '{' && close == '}') return 1;
    return 0;
}

int checkParentheses(char *expression) {
    Stack s;
    initStack(&s);

    while (*expression) {
        if (*expression == '(' || *expression == '[' || *expression == '{') {
            push(&s, *expression);
        } else if (*expression == ')' || *expression == ']' || *expression == '}') {
            if (isStackEmpty(&s)) {
                return 0;
            }
            char top = pop(&s);
            if (!isMatchingPair(top, *expression)) {
                return 0;
            }
        }
        expression++;
    }

    return isStackEmpty(&s);
}

int main() {
    char expression[20];
    printf("Enter expression: \n");
    scanf("%s",expression);
    if (checkParentheses(expression)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
