#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(int data)
{
    struct node *newNode = createNode(data);
    if (newNode == NULL)
    {
        printf("Memory Error ");
        return;
    }
    newNode->next = head;
    head = newNode;
    printf("%d was pushed successfully \n",data);
}
int pop()
{
    if (head == NULL)
    {
        printf("Empty stack, underflow!!");
        return -1;
    }
    int val = head->data;
    struct node *ptr = head;
    head = head->next;

    free(ptr);
    return val;
}
int main()
{
    int choice = 1, data;
    while (choice == 1)
    {
        printf("Enter the value :\n");
        scanf("%d", &data);
        push(data);

        printf("Press 1 to continue :");
        scanf("%d", &choice);
    }

    printf("__________________Now Popping items__________________\n");

    while (head != NULL)
    {
        int get = pop();
        printf("%d is popped \n",get);
    }
}