#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* copyTree(struct TreeNode* original) {
    if (original == NULL) {
        return NULL;
    }

    struct TreeNode* newNode = createNode(original->data);
    newNode->left = copyTree(original->left);
    newNode->right = copyTree(original->right);
    return newNode;
}

void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {

    struct TreeNode* originalTree = createNode(1);
    originalTree->left = createNode(2);
    originalTree->right = createNode(3);
    originalTree->right->right = createNode(6);
    originalTree->left->left = createNode(4);
    originalTree->left->right = createNode(5);

    struct TreeNode* copiedTree = copyTree(originalTree);

    printf("Original Tree (In-order): ");
    inOrderTraversal(originalTree);
    printf("\n");

    printf("Copied Tree (In-order): ");
    inOrderTraversal(copiedTree);
    printf("\n");
    return 0;
}
