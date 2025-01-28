#include<stdio.h>
#define Q_SIZE 4

typedef struct{
    int front,rear,size;
    int arr[Q_SIZE];
}CQueue;

void initQ(CQueue *cq){
cq->front = 0;
cq->rear = -1;
cq->size = 0;}

int isEmpty(CQueue *cq){
    return cq->size == 0;
}
int isFull(CQueue *cq){
    return cq->size == Q_SIZE;
}
void enqueue(CQueue *cq,int value){
    if(isFull(cq)){
        printf("Queue is full, cannot enqueue");
        return;
    }
    cq->rear = (cq->rear+1)%Q_SIZE;
    cq->arr[cq->rear] = value;
    cq->size++;
    printf("Enqueued %d \t",value);
}
int dequeue(CQueue *cq){
if(isEmpty(cq)){
   printf("Queue is empty, cannot dequeue");
   return -1;
   }
   int value = cq->arr[cq->front];
   cq->front = (cq->front+1)%Q_SIZE;
   cq->size--;
   return value;
}

void display(CQueue *cq){
    if(isEmpty(cq)){
        printf("Queue is empty\n");
        return;
    }
    int i;
    printf("Queue elements: ");
    for(i=0;i<cq->size;i++){
        printf("%d \t",cq->arr[(cq->front+i)%Q_SIZE]);
    }
    printf("\n");
}
int main(){
    CQueue cq;
    initQ(&cq);
    int choice,value;

    while(1){
    printf("Enter 1. to Enqueue a value \n");
    printf("Enter 2. to Dequeue \n");
    printf("Enter 3. to display the Queue \n");
    scanf("%d",&choice);
    switch(choice){
case 1:
    printf("Enter value:");
    scanf("%d",&value);
    enqueue(&cq,value);
    break;
case 2:
    printf("Dequeued element %d \n",dequeue(&cq));
    break;
case 3:
        display(&cq);
        break;}
    }
return 0;}
