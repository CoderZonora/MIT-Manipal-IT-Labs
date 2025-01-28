/*
Spell Checker
Create a basic Spell Checker using BST. 
1. read words into the BST, and then print them in alphabetical order
2. Read a word from the user and check via the bst if it is spelled correctly. Or if it is found
3. check if the entered word has siblings if it exists, if it does, have its parent node's middle lettter capitalised.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a Node for the binary search tree
struct Node {
    char data[50];
    struct Node *left;
    struct Node *right;
};

// Function to create a new Node
struct Node *createNode(char* data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, char* data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (strcmp(root->data, data) > 0) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the minimum value node in the tree
struct Node *findMin(struct Node *node) {
    struct Node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Delete an element from the binary search tree
struct Node *deleteNode(struct Node *root, char* data) {
    if (root == NULL)
        return root;

    if (strcmp(data, root->data) < 0) {
        root->left = deleteNode(root->left, data);
    } else if (strcmp(data, root->data) > 0) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findMin(root->right);
        strcpy(root->data, temp->data);
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Search for a given element in the binary search tree
struct Node *search(struct Node *root, char* data) {
    if (root == NULL || strcmp(root->data, data) == 0)
        return root;
    if (strcmp(data, root->data) < 0)
        return search(root->left, data);
    return search(root->right, data);
}

// Traverse the binary search tree and print it (in-order)
void inorderTraversal(struct Node *root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%s ", root->data);
    inorderTraversal(root->right);
}

// Driver code to test the functions
int main() {
    struct Node *root = NULL;
    char word[50];

    // 1. Read words into the BST
    printf("Enter words to add to dictionary (-1 to end): \n");
    while (1) {
        scanf("%s", word);
        if (strcmp(word, "-1") == 0) break;
        root = insert(root, word);
    }

    // 2. Print words in alphabetical order
    printf("Words in alphabetical order:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
