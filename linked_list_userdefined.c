#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void linkedTraversal()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}


struct node *createNode(int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void insertAtEnd(int data)
{
    struct node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main()
{
    // head = createNode(5);
    // struct node *first = createNode(10);
    // struct node *second = createNode(15);

    // head->next = first;
    // first->next = second;
    // second->next = NULL;
    int n;
    int choice = 1;
    while(choice == 1)
    {
        printf("Enter the value \n");
        scanf("%d",&n);
        insertAtEnd(n);

        printf("Press 1 to continue ");
        scanf("%d",&choice);
    }
    // insertAtEnd(5);
    // insertAtEnd(10);
    // insertAtEnd(15);
    // insertAtEnd(9);

    printf("Linked list traversal ");

    linkedTraversal();
    return 0;
}
