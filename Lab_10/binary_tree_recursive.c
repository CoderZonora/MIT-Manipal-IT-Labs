#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* right;
    struct Node* left;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* createBinaryTree() {
    int data;
    printf("Enter node value (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1){
        return NULL;
    }
struct Node* newNode = createNode(data);
    printf("Creating left child of %d\n", data);
    newNode->left = createBinaryTree();
    printf("Creating right child of %d\n", data);
    newNode->right = createBinaryTree();
    return newNode;
}
void printBinaryTree(struct Node* root) {
    if (root == NULL){
        return;
    };
    printBinaryTree(root->left);
    printf("%d ", root->data);
    printBinaryTree(root->right);
}


int main(){
    struct Node* tree = createBinaryTree();
    printBinaryTree(tree);
    return 0;
}
