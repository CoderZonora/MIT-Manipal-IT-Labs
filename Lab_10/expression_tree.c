#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Node structure for the expression tree
struct ExprNode {
    char data;
    struct ExprNode* left;
    struct ExprNode* right;
};

// Stack structure to help build the tree
struct Stack {
    int top;
    int capacity;
    struct ExprNode** array;
};

// Create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (struct ExprNode**)malloc(stack->capacity * sizeof(struct ExprNode*));
    return stack;
}
	
// Check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push a node to the stack
void push(struct Stack* stack, struct ExprNode* node) {
    stack->array[++stack->top] = node;
}

// Pop a node from the stack
struct ExprNode* pop(struct Stack* stack) {
    if (isEmpty(stack)) return NULL;
    return stack->array[stack->top--];
}

// Create a new tree node
struct ExprNode* createExprNode(char data) {
    struct ExprNode* newNode = (struct ExprNode*)malloc(sizeof(struct ExprNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create an expression tree from postfix expression
struct ExprNode* createExprTreeFromPostfix(char* postfix) {
    struct Stack* stack = createStack(strlen(postfix));
    
    // Traverse each character in the postfix expression
    for (int i = 0; postfix[i] != '\0'; i++) {
        // If it's an operand, create a node and push it to the stack
        if (isdigit(postfix[i]) || isalpha(postfix[i])) {
            push(stack, createExprNode(postfix[i]));
        }
        // If it's an operator, pop two nodes, make them children, and push the new tree
        else {
            struct ExprNode* node = createExprNode(postfix[i]);
            node->right = pop(stack);
            node->left = pop(stack);
            push(stack, node);
        }
    }
    // The final node in the stack is the root of the expression tree
    return pop(stack);
}

// In-order traversal for printing (to verify the tree)
void inOrderTraversal(struct ExprNode* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%c ", root->data);
    inOrderTraversal(root->right);
}

// Pre-order traversal
void preOrderTraversal(struct ExprNode* root) {
    if (root == NULL) return;
    printf("%c ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Post-order traversal
void postOrderTraversal(struct ExprNode* root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%c ", root->data);
}


// Function to evaluate the expression tree
int evaluateExprTree(struct ExprNode* root) {
    // Base case: if the node is a leaf (operand), return its integer value
    if (root->left == NULL && root->right == NULL) {
        if (isdigit(root->data)) {
            return root->data - '0';  // Convert char digit to integer
        }
    }

    // Recursively evaluate the left and right subtrees
    int leftVal = evaluateExprTree(root->left);
    int rightVal = evaluateExprTree(root->right);

    // Apply the operator at the current node
    switch (root->data) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
    }
    return 0;  // Default return in case of unexpected input
}

int main() {
    char postfix[100];

    // Get postfix expression from the user
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    // Create the expression tree
    struct ExprNode* root = createExprTreeFromPostfix(postfix);

    // Display the expression tree using different traversals
    printf("In-order traversal of the expression tree: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order traversal of the expression tree: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal of the expression tree: ");
    postOrderTraversal(root);
    printf("\n");

	    // Evaluate the expression tree
    int result = evaluateExprTree(root);
    printf("Result of evaluating the expression tree: %d\n");

    return 0;
}
