#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertBefore(Node** head, int newData, int existingData) {
    Node* newNode = createNode(newData);
    Node* current = *head;

    // Check if the list is empty or if we need to insert at the head
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->data == existingData) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    while (current->next != NULL && current->next->data != existingData) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("%d not found in the list.\n", existingData);
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void insertAfter(Node* head, int newData, int existingData) {
    Node* current = head;
    while (current != NULL && current->data != existingData) {
        current = current->next;
    }
    if (current == NULL) {
        printf("%d not found in the list.\n", existingData);
        return;
    }

    Node* newNode = createNode(newData);
    newNode->next = current->next;
    current->next = newNode;
}

void deleteElement(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in the list.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void traverseList(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void reverseList(Node** head) {
    Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void sortList(Node** head) {
    if (*head == NULL) return;

    Node *i, *j;
    int temp;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void deleteAlternate(Node** head) {
    Node *current = *head;
    while (current != NULL && current->next != NULL) {
        Node *temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }
}

void insertSorted(Node** head, int newData) {
    Node* newNode = createNode(newData);
    Node* current = *head;

    if (*head == NULL || (*head)->data >= newData) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    while (current->next != NULL && current->next->data < newData) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main() {
    Node* head = createNode(10);
    int choice, newData, existingData;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element before another element\n");
        printf("2. Insert an element after another element\n");
        printf("3. Delete a given element\n");
        printf("4. Traverse the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert an element in a sorted list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the new element: ");
                scanf("%d", &newData);
                printf("Enter the existing element before which to insert: ");
                scanf("%d", &existingData);
                insertBefore(&head, newData, existingData);
                break;

            case 2:
                printf("Enter the new element: ");
                scanf("%d", &newData);
                printf("Enter the existing element after which to insert: ");
                scanf("%d", &existingData);
                insertAfter(head, newData, existingData);
                break;

            case 3:
                printf("Enter the element to delete: ");
                scanf("%d", &newData);
                deleteElement(&head, newData);
                break;

            case 4:
                printf("Traversing the list:\n");
                traverseList(head);
                break;

            case 5:
                reverseList(&head);
                printf("List reversed.\n");
                break;

            case 6:
                sortList(&head);
                printf("List sorted.\n");
                break;

            case 7:
                deleteAlternate(&head);
                printf("Deleted every alternate node.\n");
                break;

            case 8:
                printf("Enter the new element to insert in sorted list: ");
                scanf("%d", &newData);
                insertSorted(&head, newData);
                break;

            case 9:
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("Exiting.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
