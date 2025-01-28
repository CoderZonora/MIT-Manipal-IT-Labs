#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DoublyLinkedList {
    Node* head;
} DoublyLinkedList;

DoublyLinkedList* createList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    return list;
}

void insertRear(DoublyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        newNode->prev = NULL;
        list->head = newNode;
        return;
    }

    Node* last = list->head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}

void deleteRear(DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* last = list->head;
    while (last->next != NULL) {
        last = last->next;
    }

    if (last->prev != NULL) {
        last->prev->next = NULL;
    } else {
        list->head = NULL;  // List becomes empty
    }
    free(last);
}

void insertAtPosition(DoublyLinkedList* list, int data, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (position == 0) {
        newNode->next = list->head;
        newNode->prev = NULL;
        if (list->head != NULL) {
            list->head->prev = newNode;
        }
        list->head = newNode;
        return;
    }

    Node* current = list->head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

void deleteAtPosition(DoublyLinkedList* list, int position) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* current = list->head;
    if (position == 0) {
        list->head = current->next;
        if (list->head != NULL) {
            list->head->prev = NULL;
        }
        free(current);
        return;
    }

    for (int i = 0; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    free(current);
}

void insertAfter(DoublyLinkedList* list, int targetData, int data) {
    Node* current = list->head;
    while (current != NULL && current->data != targetData) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

void insertBefore(DoublyLinkedList* list, int targetData, int data) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (list->head->data == targetData) {
        insertAtPosition(list, data, 0);
        return;
    }

    Node* current = list->head;
    while (current != NULL && current->data != targetData) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = current;
    newNode->prev = current->prev;

    if (current->prev != NULL) {
        current->prev->next = newNode;
    }
    current->prev = newNode;

    if (newNode->prev == NULL) {
        list->head = newNode;
    }
}

void traverse(DoublyLinkedList* list) {
    Node* current = list->head;
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void reverse(DoublyLinkedList* list) {
    if (list->head == NULL) {
        return;
    }

    Node* current = list->head;
    Node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        list->head = temp->prev;
    }
}

void menu() {
    DoublyLinkedList* list = createList();
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at rear\n");
        printf("2. Delete from rear\n");
        printf("3. Insert at position\n");
        printf("4. Delete at position\n");
        printf("5. Insert after an element\n");
        printf("6. Insert before an element\n");
        printf("7. Traverse the list\n");
        printf("8. Reverse the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at rear: ");
                scanf("%d", &data);
                insertRear(list, data);
                break;
            case 2:
                deleteRear(list);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(list, data, position);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(list, position);
                break;
            case 5:
                printf("Enter target data: ");
                scanf("%d", &data);
                printf("Enter data to insert after: ");
                scanf("%d", &data);
                insertAfter(list, data, data);
                break;
            case 6:
                printf("Enter target data: ");
                scanf("%d", &data);
                printf("Enter data to insert before: ");
                scanf("%d", &data);
                insertBefore(list, data, data);
                break;
            case 7:
                traverse(list);
                break;
            case 8:
                reverse(list);
                break;
            case 9:
                free(list);
                return;
            default:
                printf("Invalid choice\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
