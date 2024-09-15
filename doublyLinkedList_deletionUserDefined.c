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
    while (ptr->next != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d ", ptr->data);
    printf("\n Now in reverse order :\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

void DLLInsertion(int data, int position)
{
    struct node *temp, *newNode = (struct node *)malloc(sizeof(struct node));
    int k = 1;
    if (newNode == NULL)
    {
        printf("Memory error ");
        return;
    }
    newNode->data = data;
    if (position == 1)
    {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }
    else // insertion at any other position
    {
        temp = head;
        while (k < position - 1 && temp != NULL)
        {
            temp = temp->next;
            k++;
        }
        if (temp == NULL)
        {
            printf("Index out of bounds ");
            return;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

void DLLDeletion(int position)
{
    struct node *temp, *temp2;
    temp = head;
    int k = 1;
    if (head == NULL)
    {
        printf("List is already empty ");
        return;
    }
    if (position == 1) // to delete the head
    {
        head = head->next;
        if (head != NULL) // if head is not null, that means the new head had an element, then we set the value of previous as null, as head is always the first node in a linked list
        {
            head->prev = NULL;
        }
        free(temp);
    }
    else // delete at any other position
    {
        while (k < position && temp != NULL)
        {
            temp = temp->next;
            k++;
        }
        if (temp == NULL)
        {
            printf("Index does not exist ");
            return;
        }
        temp2 = temp->prev;
        temp2->next = temp->next;

        if (temp->next != NULL)
        {
            temp->next->prev = temp2;
        }
        free(temp);
    }
}

int main()
{
    int choice, position, value;
    choice = 1;
    while (choice == 1)
    {
        printf("Enter the value : ");
        scanf("%d", &value);

        printf("Enter the positon : ");
        scanf("%d", &position);

        DLLInsertion(value, position);

        printf("Enter 1 to continue :");
        scanf("%d", &choice);
    }
    printf("DLL after insertion : \n");
    DLLTraversal();

    printf("Enter the position of the element for deletion : ");
    scanf("%d", &position);
    DLLDeletion(position);

    printf("DLL after deletion :\n");
    DLLTraversal();
    return 0;
}