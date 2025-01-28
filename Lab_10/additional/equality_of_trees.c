#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

int isEqual(Node* tree1,Node* tree2){
    if(tree1==NULL && tree2==NULL){
        return 1;
    }
    if(tree1 == NULL || tree2 == NULL){
        return 0;
    }
    return(tree1->data == tree2->data) && isEqual(tree1->left,tree2->left) && isEqual(tree1->right,tree2->right);
}
Node* createBinaryTree(){
    int data;
    printf("Enter node value((-1) for no node): ");
    scanf("%d",&data);
    if(data==-1)
        return NULL;
    Node* newNode = createNode(data);
    printf("Creating left child of %d \n",data);
    newNode->left = createBinaryTree();
    printf("Creating right child of %d \n",data);
    newNode->right = createBinaryTree();

    return newNode;
}
int main(){
    printf("Creating first binary tree: \n");
    Node* t1 = createBinaryTree();
    printf("Creating second binary tree: \n");
    Node* t2 = createBinaryTree();
    if(isEqual(t1,t2)){
        printf("Trees are equal");
    }
    else{
        printf("Trees are not equal");
    }

    return 0;
}
