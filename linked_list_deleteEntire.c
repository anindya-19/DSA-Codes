#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head;
void linkedTraversal()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *createNode(int data)
{
    struct node *create = (struct node *)malloc(sizeof(struct node));
    create->data = data;
    create->next = NULL;
    return create;
}

void insertAtEnd(int data)
{
    struct node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void deleteAll()
{
    if (head == NULL)
    {
        printf("Empty linked list");
        return;
    }

    struct node *p = head, *q;
    while (p != NULL)
    {
       q = p->next;
       free(p);
       p=q;
    }
    head = NULL;
}


int main()
{
    int choice = 1;
    int val, index;
    while (choice == 1)
    {
        printf("Enter a value \n");
        scanf("%d", &val);
        insertAtEnd(val);

        printf("Enter 1 to continue ");
        scanf("%d", &choice);
    }
    printf("The linked list before deletion :\n");
    linkedTraversal();

    printf("The linked list after deleting all the elements :\n");
    deleteAll();
    linkedTraversal();
}