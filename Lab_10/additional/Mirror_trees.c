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

int isMirror(Node* t1,Node* t2){
    if(t1 == NULL && t2 == NULL) {
        return 1;
    }
    if (t1 == NULL || t2 == NULL) {
        return 0;
    }
    return (t1->data == t2->data &&
            isMirror(t1->left, t2->right) &&
            isMirror(t1->right, t2->left));
}


int main(){
    Node* tree1 = createNode(1);
    tree1->left = createNode(2);
    tree1->right = createNode(3);

    Node* tree2 = createNode(1);
    tree2->left = createNode(3);
    tree2->right = createNode(2);
    if (isMirror(tree1, tree2)) {
        printf("The trees are mirror images of each other.\n");
    } else {
        printf("The trees are not mirror images of each other.\n");
    }
    free(tree1->left);
    free(tree1->right);
    free(tree1);
    free(tree2->left);
    free(tree2->right);
    free(tree2);

    return 0;

}
