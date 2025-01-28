#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to initialize a doubly linked list with a header node
struct Node* createHeader() {
    struct Node* header = createNode(0); // Header node with data 0 (can be used to store length)
    header->next = header->prev = header; // Initially, header points to itself
    return header;
}

// Function to insert a new node at the end of the list
void insertEnd(struct Node* header, int data) {
    struct Node* newNode = createNode(data);
    struct Node* tail = header->prev; // Find the last node (tail)
    
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = header;
    header->prev = newNode;
}

// Function to display the list
void displayList(struct Node* header) {
    if (header->next == header) { // List is empty
        printf("The list is empty.\n");
        return;
    }
    
    struct Node* current = header->next;
    printf("Doubly Linked List: ");
    while (current != header) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to sort the doubly linked list in ascending order
void sortDoublyLinkedList(struct Node* header) {
    if (header->next == header || header->next->next == header) {
        // List is empty or has only one node; no sorting needed
        return;
    }

    struct Node* current = header->next->next; // Start from the second node
    while (current != header) {
        struct Node* next = current->next;
        struct Node* position = current->prev;
        
        // Move `current` back to the right position in sorted order
        while (position != header && position->data > current->data) {
            position = position->prev;
        }

        // Remove `current` from its original position
        current->prev->next = current->next;
        current->next->prev = current->prev;

        // Insert `current` after `position`
        current->next = position->next;
        current->prev = position;
        position->next->prev = current;
        position->next = current;

        current = next;
    }
}

// Function to reverse the doubly linked list
void reverseList(struct Node* header) {
    if (header->next == header || header->next->next == header) {
        // List is empty or has only one node; no reversing needed
        return;
    }

    struct Node* current = header->next;
    struct Node* temp = NULL;
    
    // Swap next and prev pointers for each node
    while (current != header) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node (which is `prev` after swapping)
    }
    
    // Swap the header's next and prev pointers
    temp = header->prev;
    header->prev = header->next;
    header->next = temp;
}

// Main function to demonstrate reading, displaying, and sorting the list
int main() {
    struct Node* header = createHeader();
    int data;
    
    printf("Enter elements to insert into the doubly linked list (-1 to end):\n");
    while (1) {
        printf("Enter data: ");
        scanf("%d", &data);
        if (data == -1) break; // Stop input on entering -1
        insertEnd(header, data);
    }
    
    printf("\nOriginal list:\n");
    displayList(header);
    
    sortDoublyLinkedList(header);
    
    printf("\nSorted list:\n");
    displayList(header);
    
    return 0;
}
