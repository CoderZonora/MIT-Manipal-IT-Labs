#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* createBinaryTree() {
    int data;
    printf("Enter node value (-1 for no node): ");
    scanf("%d", &data);
    if (data == -1) {
        return NULL;
    }
    struct Node* newNode = createNode(data);
    printf("Enter left child of %d\n", data);
    newNode->left = createBinaryTree();
    printf("Enter right child of %d\n", data);
    newNode->right = createBinaryTree();
    return newNode;
}

void inOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void preOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);

        if (current->right) stack[++top] = current->right;
        if (current->left) stack[++top] = current->left;
    }
}

void postOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;
    struct Node* lastVisited = NULL;
    struct Node* current = root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top];
        if (current->right == NULL || current->right == lastVisited) {
            printf("%d ", current->data);
            lastVisited = stack[top--];
            current = NULL;
        } else {
            current = current->right;
        }
    }
}



struct Node* findParent(struct Node* root, int element) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return NULL;
    }
    if ((root->left != NULL && root->left->data == element) ||
        (root->right != NULL && root->right->data == element)) {
        return root;
    }
    struct Node* leftParent = findParent(root->left, element);
    if (leftParent != NULL) {
        return leftParent;
    }
    return findParent(root->right, element);
}
int depth(struct Node* root) {
    if (root == NULL) return 0;
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}
int findAncestors(struct Node* root, int element) {
    if (root == NULL) return 0;
    if (root->data == element) return 1;

    if (findAncestors(root->left, element) || findAncestors(root->right, element)) {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}
int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    struct Node* root = createBinaryTree();

    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    int element;
    printf("Enter element to find parent: ");
    scanf("%d", &element);
    struct Node* parent = findParent(root, element);
    if (parent != NULL) {
        printf("Parent of %d is %d\n", element, parent->data);
    } else {
        printf("Parent not found or it is the root.\n");
    }

    printf("Depth of the tree: %d\n", depth(root));

    printf("Enter element to find ancestors: ");
    scanf("%d", &element);
    printf("Ancestors of %d: ", element);
    if (!findAncestors(root, element)) {
        printf("No ancestors found or element not present.\n");
    }
    printf("\n");

    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}
