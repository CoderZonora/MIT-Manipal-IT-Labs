#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Node structure for the tree
struct tnode {
    int data;
    struct tnode *llink;
    struct tnode *rlink;
};

// Queue structure for level-order traversal
struct tnode* queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

// Function to add a node to the queue
void addq(struct tnode* node) {
    if (rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = node;
}

// Function to delete a node from the queue
struct tnode* delete() {
    if (front == -1) {
        printf("Queue underflow\n");
        return NULL;
    }
    struct tnode* node = queue[front++];
    if (front > rear) {  // Reset the queue when it's empty
        front = rear = -1;
    }
    return node;
}

// Level-order traversal function
void level_order(struct tnode* ptr) {
    if (!ptr) return;  // empty tree

    addq(ptr);  // Enqueue the root node

    while (front != -1) {
        ptr = delete();  // Dequeue a node
        if (ptr) {
            printf("%d ", ptr->data);  // Print the node's data

            // Enqueue left and right children if they exist
            if (ptr->llink) {
                addq(ptr->llink);
            }
            if (ptr->rlink) {
                addq(ptr->rlink);
            }
        }
    }
}

// Function to create a new node
struct tnode* createNode(int data) {
    struct tnode* newNode = (struct tnode*)malloc(sizeof(struct tnode));
    newNode->data = data;
    newNode->llink = newNode->rlink = NULL;
    return newNode;
}

// Sample tree for testing
int main() {
    // Creating a sample tree
    struct tnode* root = createNode(1);
    root->llink = createNode(2);
    root->rlink = createNode(10);
    root->llink->llink = createNode(4);
    root->llink->rlink = createNode(5);
    root->rlink->llink = createNode(6);
    root->rlink->rlink = createNode(7);

    // Perform level-order traversal
    printf("Level-order Traversal: ");
    level_order(root);
    printf("\n");

    return 0;
}
	