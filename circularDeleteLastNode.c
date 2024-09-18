#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
int circularTraverse()
{
    struct node *ptr = head;
    int count = 0;
    if (head == NULL)
    {
        printf("List does not exist ");
        return 0;
    }
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
        count++;
    } while (ptr != head);
    printf("\n");
    return count;
}

void CLLInsertAtEnd(int data)
{
    struct node *current = head;
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory Error");
        return;
    }

    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    while (current->next != head)
    {
        current = current->next;
    }
    newNode->next = head;
    current->next = newNode;
}

void CLLDeleteLast()
{
    struct node *p = head;

    if(head == NULL)
    {
        printf("List already empty ");
        return;
    }
    if(head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }
    while(p->next->next != head)
    {
        p = p->next;
    }
    struct node *temp = p->next;
    p->next = temp->next;
    free(temp);
}

int main()
{
    int choice = 1, val;
    while (choice == 1)
    {
        printf("Enter the value :");
        scanf("%d", &val);
        CLLInsertAtEnd(val);

        printf("Press 1 to continue :");
        scanf("%d", &choice);
    }

    printf("The Circular Linked List after insertions :\n");
    printf("The length of the linked list is :%d \n",circularTraverse());

    CLLDeleteLast();
    printf("The circular linked list after deletion of first node :\n");
    printf("The current length of the linked list :%d",circularTraverse());
    return 0;
}