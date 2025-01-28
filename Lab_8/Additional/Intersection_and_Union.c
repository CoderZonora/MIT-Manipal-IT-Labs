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

// Function to check if a node with a given value exists in the list
int exists(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1; // Value exists
        }
        current = current->next;
    }
    return 0; // Value does not exist
}

// Function to perform union of two doubly linked lists
Node* unionLists(Node* X1, Node* X2) {
    Node* result = NULL;

    // Insert all elements from the first list
    Node* current = X1;
    while (current != NULL) {
        insertRear(&result, current->data);
        current = current->next;
    }

    // Insert elements from the second list if they are not already present
    current = X2;
    while (current != NULL) {
        if (!exists(result, current->data)) {
            insertRear(&result, current->data);
        }
        current = current->next;
    }

    return result;
}

// Function to perform intersection of two doubly linked lists
Node* intersectionLists(Node* X1, Node* X2) {
    Node* result = NULL;

    // Find common elements
    Node* current = X1;
    while (current != NULL) {
        if (exists(X2, current->data)) {
            insertRear(&result, current->data);
        }
        current = current->next;
    }

    return result;
}

// Main function to demonstrate union and intersection
int main() {
    Node* X1 = NULL;
    Node* X2 = NULL;

    // Insert elements into the first list
    insertRear(&X1, 1);
    insertRear(&X1, 2);
    insertRear(&X1, 3);
    insertRear(&X1, 4);
    printf("List X1: ");
    printList(X1);

    // Insert elements into the second list
    insertRear(&X2, 3);
    insertRear(&X2, 4);
    insertRear(&X2, 5);
    insertRear(&X2, 6);
    printf("List X2: ");
    printList(X2);

    // Perform union
    Node* unionResult = unionLists(X1, X2);
    printf("Union of X1 and X2: ");
    printList(unionResult);

    // Perform intersection
    Node* intersectionResult = intersectionLists(X1, X2);
    printf("Intersection of X1 and X2: ");
    printList(intersectionResult);

    // Free memory (not shown for brevity)
    // Proper memory management should be implemented here.

    return 0;
}

