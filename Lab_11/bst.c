#include <stdio.h>
#include <stdlib.h>

// Define a Node for the binary search tree
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new Node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert an element into the binary search tree
struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to find the minimum value node in the tree
struct Node *findMin(struct Node *node)
{
    struct Node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}


// Delete an element from the binary search tree
struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


// Search for a given element in the binary search tree
struct Node *search(struct Node *root, int data)
{
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

struct Node *iterativeSearchBST(int item, struct Node *root)
{
    while (root != NULL && item != root->data)
    {
        if (item < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// Traverse the binary search tree and print it (in-order)
void inorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void countnodes(struct Node *root,int *p)
{
	if(root==NULL)
		return;
	*p = *p + 1;
	countnodes(root->left,p);
	countnodes(root->left,p);
}
// Driver code to test the functions
int main()
{
    struct Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    int q=0;
    countnodes(root,&q);
	printf("Number of nodes = %d \n",q);
	
	
    printf("Deleting 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Searching for 40: ");
    struct Node *searchResult = search(root, 40);
    if (searchResult != NULL)
        printf("Found %d\n", searchResult->data);
    else
        printf("Not Found\n");
	
	printf("Searching for 40 (iterative): ");
    struct Node *iterativeSearchResult = iterativeSearchBST(40, root);
    if (iterativeSearchResult != NULL)
        printf("Found %d\n", iterativeSearchResult->data);
    else
        printf("Not Found\n");

    return 0;
}