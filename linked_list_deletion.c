#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head;
void linkedTraversal(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void deleteFromLinkedList() // delete first node
{
    if(head == NULL)
    {
        printf("Linked list is empty \n");
        return NULL;
    }
    struct node *p = head;
    head = head->next;
    free(p);
}

void deleteAtIndex(int index)
{
    int k = 1;
    struct node *p, *q;
    p = head;
    while (p != NULL && k < index)
    {
        k++;
        q = p;
        p = p->next;
    }
    if (p == NULL)
    {
        printf("Position does not exist ");
    }
    else
    {
        q->next = p->next;
        free(p);
    }
}

// void deleteLastNode() // deleting the last element
// {
//     if (head == NULL)
//     {
//         printf("Linked list is empty");
//         return;
//     }
//     struct node *q, *p = head;
//     while (p->next != NULL)
//     {
//         q=p;
//         p = p->next;
//     }
//     q->next = p->next;
//     free(p);
// }
// void deleteAll()
// {
//     if (head == NULL)
//     {
//         printf("Empty linked list");
//         return;
//     }

//     struct node *p = head, *q;
//     while (p != NULL)
//     {
//        q = p->next;
//        free(p);
//        p=q;
//     }
//     head = NULL;
// }

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

    linkedTraversal(head);
    // printf("after deleting all the elements \n");
    //  deleteFromLinkedList();
    printf("Enter the index where you want to delete :");
    scanf("%d", &index);
    deleteAtIndex(index);

    // deleteLastNode();
    // deleteAll();

    linkedTraversal(head);
    return 0;
}
