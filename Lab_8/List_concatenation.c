#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the rear end of a doubly linked list
void insertRear(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to concatenate two doubly linked lists
void concatenate(Node** X1, Node** X2) {
    if (*X1 == NULL) {
        *X1 = *X2;
    } else {
        Node* last = *X1;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = *X2;
        if (*X2 != NULL) {
            (*X2)->prev = last;
        }
    }
    *X2 = NULL; // Optional: Clear X2 after concatenation
}

int main() {
    Node* X1 = NULL;
    Node* X2 = NULL;

    // Insert elements into the first list
    insertRear(&X1, 1);
    insertRear(&X1, 2);
    insertRear(&X1, 3);
    printf("List X1: ");
    printList(X1);

    // Insert elements into the second list
    insertRear(&X2, 4);
    insertRear(&X2, 5);
    insertRear(&X2, 6);
    printf("List X2: ");
    printList(X2);

    // Concatenate X2 into X1
    concatenate(&X1, &X2);

    // Display the concatenated list
    printf("Concatenated List X1: ");
    printList(X1);

    // Free the allocated memory (not shown for brevity)
    // Proper memory management should be implemented here.

    return 0;
}

