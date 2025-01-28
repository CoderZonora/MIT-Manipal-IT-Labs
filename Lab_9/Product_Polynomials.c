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


Node* product(Node* h1,Node* h2)
{   Node* result = NULL;
    Node* t1;Node*t2;

     t1=h1,t2=h2;   
    while(t1!=NULL)
    {
        while(t2!=NULL)
        {
            insertTerm(&result,t1->coefficient * t2->coefficient,t1->exponent+t2->exponent);
            t2 = t2->link;
        }
        t2 = h2;
        t1 = t1 -> link;
    }
    return result;
}

Node* fixpro(Node* result) {
    Node* curr = result;

    // Traverse each node in the polynomial list
    while (curr != NULL) {
        Node* temp = curr;
        //Node* prev = curr;
        
        // Check if there are any nodes with the same exponent after the current node
        while (temp->link != NULL) {
            if (temp->link->exponent == curr->exponent) {
                // Add coefficients if exponents match
                curr->coefficient += temp->link->coefficient;

                // Remove the duplicate node
                Node* duplicate = temp->link;
                temp->link = temp->link->link;
                free(duplicate);
            } else {
                // Move to the next node
                temp = temp->link;
            }
        }

        // Move to the next unique exponent
        curr = curr->link;
    }

    return result;
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
int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    printf("Enter terms for the first polynomial (coefficient exponent), type -1 to end: \n");
    while (1) {
        int coefficient, exponent;
        scanf("%d", &coefficient);
        if (coefficient == -1)
            break;
        scanf("%d", &exponent);
        insertTerm(&poly1, coefficient, exponent);
    }
    printf("Enter terms for the second polynomial (coefficient exponent), type -1 to end: \n");
    while (1) {
        int coefficient, exponent;
        scanf("%d", &coefficient);
        if (coefficient == -1)
            break;
        scanf("%d", &exponent);
        insertTerm(&poly2, coefficient, exponent);
    }
    Node* res2 = product(poly1, poly2);
    res2 = fixpro(res2);  // Combine terms in the product polynomial

    printf("Resultant Polynomial (Addition): \n");
    printPolynomial(result);
    printf("Resultant Polynomial (Product): \n");
    printPolynomial(res2);

    return 0;
}
