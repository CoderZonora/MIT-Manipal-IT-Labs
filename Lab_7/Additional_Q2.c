#include<stdio.h>
struct Node{
    char* data;
    struct Node* link = NULL;
};
struct Node* merge(struct Node* head1, struct Node* head2){
    struct Node* head;
    struct Node* curr = head;
    while(curr!=NULL){
    while(head1!=NULL && head2!=NULL){
        curr = head1;
        curr->link = head2;
        head1 = head1->link;
        head2 = head2->link;
    }
        curr = curr->link;
    }
    return curr;
};
int main(){
return 0;
}
