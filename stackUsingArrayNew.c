#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int size;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if(ptr->top == ptr->size-1)
        return 1;
    return 0;
}

void push(struct stack *ptr,int val)
{
    if(isFull(ptr))
    {
        printf("Overflow!! The stack is already full");
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
    printf("%d was pushed successfully !\n",val);
}

int pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("Underflow, stack is empty!");
        return -1;
    }
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val; // val contains the value that we just popped
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 10;
    sp->arr = (int *)malloc(sp->size * sizeof(int)); // creating an integer array
    int val;
    int choice = 1;
    while(choice == 1)
    {
        printf("Enter the value: ");
        scanf("%d",&val);

        push(sp,val);

        printf("Press 1 to continue : ");
        scanf("%d",&choice);
    }

    printf("__________________Now Popping Items_______________________ \n");
    while(sp->top != -1)
    {
        int get = pop(sp);
        printf("%d is popped \n",get);
    }
}