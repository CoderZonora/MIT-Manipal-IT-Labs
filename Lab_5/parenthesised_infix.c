#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    char *items[MAX_SIZE];
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

void push(Stack *s, const char *value) {
    if (isStackFull(s)) {
        printf("Stack is full\n");
        exit(1);
    }
    s->items[++(s->top)] = strdup(value);
}

char* pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    char *value = s->items[(s->top)--];
    return value;
}

char* peek(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return s->items[s->top];
}

char* infixFromPostfix(const char *postfix) {
    Stack s;
    initStack(&s);

    while (*postfix) {
        if (isalnum(*postfix)) {
            char op[2] = {*postfix, '\0'};
            push(&s, op);
        } else {
            char *right = pop(&s);
            char *left = pop(&s);

            char *result = (char *)malloc(MAX_SIZE);
            snprintf(result, MAX_SIZE, "(%s%c%s)", left, *postfix, right);

            push(&s, result);
            free(left);
            free(right);
        }
        postfix++;
    }

    return pop(&s);
}

int main() {
    const char *postfix = "AB+C*";

    char *infix = infixFromPostfix(postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Fully Parenthesized Infix Expression: %s\n", infix);

    free(infix);

    return 0;
}

