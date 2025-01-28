#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked circular list
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

// Function to insert a node into a doubly linked circular list
void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        // If the list is empty, create the first node
        *head = newNode;
        newNode->next = newNode; // Point next to itself
        newNode->prev = newNode; // Point prev to itself
    } else {
        Node* last = (*head)->prev; // Last node
        last->next = newNode;        // Link last node to new node
        newNode->next = *head;       // Link new node to head
        newNode->prev = last;        // Link new node to last
        (*head)->prev = newNode;     // Link head to new node
    }
}

// Function to delete a node from the doubly linked circular list
void deleteNode(Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = *head;
    do {
        if (current->data == key) {
            if (current->next == current) {
                // Only one node in the list
                free(current);
                *head = NULL;
                return;
            } else {
                // More than one node in the list
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (current == *head) {
                    *head = current->next; // Update head if necessary
                }
                free(current);
                return;
            }
        }
        current = current->next;
    } while (current != *head);

    printf("Element %d not found in the list.\n", key);
}

// Function to traverse the list and print it
void traverse(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

// Menu driven program
void menu() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Traverse the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                printf("Elements in the list: ");
                traverse(head);
                break;
            case 4:
                // Free the list (not shown for brevity)
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}

