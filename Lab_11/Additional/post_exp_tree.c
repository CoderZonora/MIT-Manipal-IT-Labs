//Program to create expression tree and evaluate it

include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define a node structure
typedef struct Node {
    char value;
    struct Node* left;
    struct Node* right;
} Node;

// Stack structure for nodes
typedef struct Stack {
    Node* data;
    struct Stack* next;
} Stack;

// Function to push a node onto the stack
void push(Stack** stack, Node* node) {
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    new_stack->data = node;
    new_stack->next = *stack;
    *stack = new_stack;
}

// Function to pop a node from the stack
Node* pop(Stack** stack) {
    if (*stack == NULL) {
        return NULL;
    }
    Stack* temp = *stack;
    *stack = (*stack)->next;
    Node* popped_node = temp->data;
    free(temp);
    return popped_node;
}

// Function to create a new node
Node* create_node(char value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

// Function to check if a character is an operator
int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to construct an expression tree from postfix expression
Node* construct_tree(char* postfix) {
    Stack* stack = NULL;
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        
        // If the character is an operand, push it as a new node
        if (isdigit(ch)) {
            push(&stack, create_node(ch));
        }
        // If the character is an operator, pop two nodes, create a new node, and push it
        else if (is_operator(ch)) {
            Node* node = create_node(ch);
            node->right = pop(&stack);
            node->left = pop(&stack);
            push(&stack, node);
        }
    }
    // The final node on the stack is the root of the expression tree
    return pop(&stack);
}

// Function to evaluate the expression tree
int evaluate_tree(Node* root) {
    // If it's a leaf node, return its integer value
    if (!is_operator(root->value)) {
        return root->value - '0';
    }
    
    // Evaluate left and right subtrees
    int left_val = evaluate_tree(root->left);
    int right_val = evaluate_tree(root->right);
    
    // Apply the operator at this node to the values obtained
    switch (root->value) {
        case '+': return left_val + right_val;
        case '-': return left_val - right_val;
        case '*': return left_val * right_val;
        case '/': return left_val / right_val;
    }
    return 0;
}

// Free the memory of the tree
void free_tree(Node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// Main function to test the program
int main() {
    char postfix[] = "53+82-*";
    Node* root = construct_tree(postfix);
    int result = evaluate_tree(root);
    printf("The result of the postfix expression %s is: %d\n", postfix, result);
    
    // Free the tree memory
    free_tree(root);
    return 0;
}
