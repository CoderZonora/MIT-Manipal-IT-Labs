#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct {
    int top;
    char items[MAX_SIZE];
} CharStack;

void initCharStack(CharStack *s) {
    s->top = -1;
}

int isCharStackEmpty(CharStack *s) {
    return s->top == -1;
}

int isCharStackFull(CharStack *s) {
    return s->top == MAX_SIZE - 1;
}

void pushChar(CharStack *s, char value) {
    if (isCharStackFull(s)) {
        printf("Character stack is full\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

char popChar(CharStack *s) {
    if (isCharStackEmpty(s)) {
        printf("Character stack is empty\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

char peekChar(CharStack *s) {
    if (isCharStackEmpty(s)) {
        printf("Character stack is empty\n");
        exit(1);
    }
    return s->items[s->top];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    CharStack opStack;
    initCharStack(&opStack);
    int k = 0;

    while (*infix) {
        if (isalnum(*infix)) {
            postfix[k++] = *infix;
        } else if (*infix == '(') {
            pushChar(&opStack, *infix);
        } else if (*infix == ')') {
            while (!isCharStackEmpty(&opStack) && peekChar(&opStack) != '(') {
                postfix[k++] = popChar(&opStack);
            }
            if (!isCharStackEmpty(&opStack) && peekChar(&opStack) == '(') {
                popChar(&opStack);
            }
        } else {
            while (!isCharStackEmpty(&opStack) && precedence(peekChar(&opStack)) >= precedence(*infix)) {
                postfix[k++] = popChar(&opStack);
            }
            pushChar(&opStack, *infix);
        }
        infix++;
    }
    while (!isCharStackEmpty(&opStack)) {
        postfix[k++] = popChar(&opStack);
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s",infix);
    infixToPostfix(infix, postfix);
    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}
