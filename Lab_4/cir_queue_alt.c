#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 4

typedef struct {
    int front, rear;
    int arr[Q_SIZE];
} CQueue;

// Initialize the queue
void initQ(CQueue *cq) {
    cq->front = -1;
    cq->rear = -1;
}

// Check if the queue is empty
int isEmpty(CQueue *cq) {
    return cq->front == -1;
}

// Check if the queue is full
int isFull(CQueue *cq) {
    return (cq->rear + 1) % Q_SIZE == cq->front;
}

// Enqueue operation
void enqueue(CQueue *cq, int value) {
    if (isFull(cq)) {
        printf("Queue is full, cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty(cq)) {
        cq->front = 0; // Set front to 0 if the queue was empty
    }
    cq->rear = (cq->rear + 1) % Q_SIZE; // Move rear to the next position
    cq->arr[cq->rear] = value;
    printf("Enqueued %d\n", value);
}

// Dequeue operation
int dequeue(CQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }

    int value = cq->arr[cq->front];
    if (cq->front == cq->rear) {
        // Queue becomes empty after this dequeue
        cq->front = -1;
        cq->rear = -1;
    } else {
        cq->front = (cq->front + 1) % Q_SIZE; // Move front to the next position
    }
    return value;
}

// Display the queue
void display(CQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = cq->front;
    do {
        printf("%d ", cq->arr[i]);
        i = (i + 1) % Q_SIZE;
    } while (i != (cq->rear + 1) % Q_SIZE);
    printf("\n");
}

// Main function to demonstrate the circular queue
int main() {
    CQueue cq;
    initQ(&cq);
    int choice, value;

    while (1) {
        printf("\nEnter 1 to Enqueue\n");
        printf("Enter 2 to Dequeue\n");
        printf("Enter 3 to Display Queue\n");
        printf("Enter 4 to Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&cq, value);
                break;
            case 2:
                value = dequeue(&cq);
                if (value != -1)
                    printf("Dequeued %d\n", value);
                break;
            case 3:
                display(&cq);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
