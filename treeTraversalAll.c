#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inOrderTravesal(struct node *root)
{
    if(root != NULL)
    {
        inOrderTravesal(root->left);
        printf("%d  ",root->data);
        inOrderTravesal(root->right);
    }
}
void postOrderTraversal(struct node *root)
{
    if(root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ",root->data);
    }
}
void preOrderTraversal(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}


int main()
{
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    
    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2 

    //inOrderTravesal(p);
    // preOrderTraversal(p);
    postOrderTraversal(p);
}