#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char* data;
    struct Node* link;
}Node;

struct Node* insert(Node* head, char* data){
    if(head == NULL){
   Node* newNode = (Node*)malloc(sizeof(Node));
   newNode->data = data;
   newNode->link = NULL;
   return newNode;
   }

   head->link = insert(head->link,data);
   return head;
}
void display(Node* head){
    if(head==NULL){
            printf("NULL");
        return;
    }
    printf("%s -> ",head->data);
    display(head->link);
}

int main(){
struct Node* head = NULL;
head = insert(head, "My");
head = insert(head, "Name");
head = insert(head, "is");
display(head);
}
