#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int digit;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int digit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->digit = digit;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a digit at the end of the linked list
void insertEnd(Node** head, int digit) {
    Node* newNode = createNode(digit);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(Node* head) {
    if (head == NULL) {
        printf("0");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->digit);
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two linked lists representing long integers
Node* addLargeNumbers(Node* num1, Node* num2) {
    Node* result = NULL;
    Node* temp1 = num1;
    Node* temp2 = num2;
    int carry = 0;

    // Adding digits from both lists
    while (temp1 != NULL || temp2 != NULL || carry != 0) {
        int sum = carry;
        if (temp1 != NULL) {
            sum += temp1->digit;
            temp1 = temp1->next;
        }
        if (temp2 != NULL) {
            sum += temp2->digit;
            temp2 = temp2->next;
        }

        carry = sum / 10; // Calculate new carry
        insertEnd(&result, sum % 10); // Insert the result digit
    }

    return result;
}

// Main function to demonstrate addition of two long integers
int main() {
    Node* num1 = NULL;
    Node* num2 = NULL;

    // Input first long positive integer
    printf("Enter the first long positive integer: ");
    char input1[1000];
    scanf("%s", input1);
    for (int i = 0; input1[i] != '\0'; i++) {
        insertEnd(&num1, input1[i] - '0'); // Convert char to int
    }

    // Input second long positive integer
    printf("Enter the second long positive integer: ");
    char input2[1000];
    scanf("%s", input2);
    for (int i = 0; input2[i] != '\0'; i++) {
        insertEnd(&num2, input2[i] - '0'); // Convert char to int
    }

    // Add the two numbers
    Node* result = addLargeNumbers(num1, num2);

    // Print the result
    printf("Sum: ");
    printList(result);

    // Free memory (not shown for brevity)
    // Proper memory management should be implemented here.

    return 0;
}

