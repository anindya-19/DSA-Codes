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
        printf("Empty list");
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
void insertAtFront(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *current = head;
    if (newNode == NULL)
    {
        printf("Memory Error");
        return;
    }
    newNode->data = data;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head; // points to itself as it is the only node
    }
    else
    {
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

int main()
{
    int choice = 1,val;
    while (choice == 1)
    {
        printf("Enter the value :");
        scanf("%d",&val);
        insertAtFront(val);
        printf("Enter 1 to continue :");
        scanf("%d",&choice);
    }

    printf("The circular linked list after insertions :\n");
    printf("The size of the linked list is :",circularTraverse());
    return 0;
}