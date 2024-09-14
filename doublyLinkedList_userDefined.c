#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
void DLLTraversal()
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("List is empty ");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void DLLInsertion(int data, int position)
{
    int k = 1;
    struct node *temp, *temp2;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory error ");
        return;
    }

    newNode->data = data;

    if (position == 1) // insertion at first position
    {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) // that means head exists already
        {
            head->prev = newNode;
        }
        head = newNode; // new node becomes the new head
        return;
    }

    // insert at any other position
    temp = head;
    while (k < position - 1 && temp != NULL) // we go k-1 to reach 1 position before the desired index
    {
        temp = temp->next;
        k++;
    }
    if (temp == NULL)
    {
        printf("Declared position does not exist ");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) // returns true if temp's next is not the last node of the list
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}
int main()
{
    int choice = 1, pos, val;
    while (choice == 1)
    {
        printf("Enter the data :");
        scanf("%d", &val);

        printf("Enter the position :");
        scanf("%d", &pos);
        DLLInsertion(val, pos);

        printf("Press 1 to continue :");
        scanf("%d", &choice);
    }
    printf("Doubly Linked list after insertions :\n");
    DLLTraversal();
    return 0;
}