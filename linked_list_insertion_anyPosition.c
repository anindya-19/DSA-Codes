#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void traversal()
{
    if (head == NULL)
    {
        printf("Empty List :\n");
        return;
    }
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d  ", current->data);
        current = current->next;
    }
    printf("NULL");
    printf("\n");
}

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertion(int data, int position)
{
    int k = 1;
    struct node *newNode = createNode(data);
    struct node *p = head, *q = NULL;
    if (newNode == NULL)
    {
        printf("Memory error ");
        return;
    }

    // Case 1: insertion at the begining
    if (position == 1)
    {
        newNode->next = p;
        head = newNode;
        return;
    }
    
    while (p != NULL && k < position)
    {
        k++;
        q = p; // q gets the previous node
        p = p->next;
    }
    if(k != position)
    {
        printf("Position is out of bounds \n");
        free(newNode);
        return;
    }

    //Case 2: insertion at any position
    q->next = newNode;
    newNode->next = p;

}
int main()
{
    int val, position, choice = 1;
    while (choice == 1)
    {
        printf("Enter the value :");
        scanf("%d", &val);

        printf("Enter the position : ");
        scanf("%d", &position);

        insertion(val, position);

        printf("Enter 1 to continue :");
        scanf("%d", &choice);
    }

    printf("Linked list after insertion \n");
    traversal();
    return 0;
}