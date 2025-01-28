#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coefficient;
    int exponent;
    struct Node* link;
}Node;
Node* createNode(int coefficient,int exponent){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->link = NULL;

    return newNode;

}
void insertTerm(Node** head,int coefficient,int exponent){
    Node* newNode = createNode(coefficient,exponent);
    if(*head==NULL || (*head)->exponent < exponent) {
        newNode->link = *head;
        *head = newNode;
        return;
    }
    Node* curr = *head;
    while(curr->link != NULL && curr->link->exponent > exponent){
        curr = curr->link;
    }
    if(curr->exponent == exponent){
        curr->coefficient += coefficient;
        free(newNode);
    }
    else{
        newNode->link = curr->link;
        curr->link = newNode;
    }
}

Node* addPolynomials(Node* poly1,Node* poly2){
    Node* result = NULL;

    while(poly1!= NULL && poly2 != NULL){
        if(poly1->exponent > poly2->exponent){
            insertTerm(&result,poly1->coefficient,poly1->exponent);
            poly1 = poly1->link;
        }
        else if(poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient,poly2->exponent);
            poly2 = poly2->link;
        }
        else{
            insertTerm(&result, poly1->coefficient+poly2->coefficient, poly1->exponent);
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
    }

    while(poly1 != NULL){
        insertTerm(&result,poly1->coefficient,poly1->exponent);
        poly1 = poly1->link;
    }
    while(poly2!=NULL){
        insertTerm(&result,poly2->coefficient,poly2->exponent);
        poly2 = poly2->link;
    }
    return result;
}

Node* product(Node* h1,Node* h2,Node* f)
{Node* t1,t2;
    while(1)
    {
     t1=h1,t2=h2;   
    while(h1!=NULL)
    {
        while(h2!=NULL)
        {
            addNode(f,h1->exp+h2->exp)
        }
    }
    }
}
void printPolynomial(Node* head){
    if(head==NULL){
        printf("-\n");
        return;
    }
    Node* curr = head;
    while(curr!=NULL){
        if(curr!= head && curr->coefficient > 0){
            printf("+ ");
        }
        printf("%dx^%d",curr->coefficient,curr->exponent);
        curr = curr->link;
    }
    printf("\n");
}
int main(){
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    printf("Enter terms for the first polynomial (coefficient exponent), type -1 to end: \n");
    while(1){
        int coefficient,exponent;
        scanf("%d",&coefficient);
        if(coefficient == -1)
            break;
        scanf("%d",&exponent);
        insertTerm(&poly1,coefficient,exponent);
    }
    printf("Enter terms for the second polynomial (coefficient exponent), type -1 to end: \n");
    while(1){
        int coefficient,exponent;
        scanf("%d",&coefficient);
        if(coefficient == -1)
            break;
        scanf("%d",&exponent);
        insertTerm(&poly2,coefficient,exponent);
    }
    Node* result = addPolynomials(poly1,poly2);
    printf("Resultant Polynomial: \n");
    printPolynomial(result);

    return 0;}
