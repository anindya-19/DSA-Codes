#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int capacity;
    int *arr;
};

struct queue
{
    struct stack *stack1;
    struct stack *stack2;
};

struct stack *createStack(int capacity)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->capacity = capacity;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->capacity * sizeof(int));

    return sp;
}

int isFull(struct stack *stack)
{
    if (stack->top == stack->capacity - 1)
        return 1;
    return 0;
}
int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
        return 1;
    return 0;
}

void push(struct stack *sp, int val)
{
    if (isFull(sp))
    {
        printf("Stack Overflow!!");
        return;
    }
    sp->arr[++sp->top] = val;
}
int pop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack Underflow! \n");
        return -1;
    }
    return sp->arr[sp->top--];
}
struct queue *createQueue(int capacity)
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->stack1 = createStack(capacity);
    q->stack2 = createStack(capacity);

    return q;
}
void enqueue(struct queue *q, int data)
{
    push(q->stack1,data);
    printf("%d was enqueued successfully! \n",data);
}
int dequeue(struct queue *q)
{
    int data;

    // if stack2 is empty, transfer all the values of stack1 to stack2 
    if(isEmpty(q->stack2))
    {
        if(isEmpty(q->stack1))
        {
            printf("Queue is already empty!! \n");
            return -1;
        }  
        while (!isEmpty(q->stack1))
        {
            push(q->stack2,pop(q->stack1)); //push into stack2 the values of stack1
        }
    }
    //if stack2 is not empty, then pop its values 
    data = pop(q->stack2);
    printf("%d was successfully dequeued \n",data);
    return data;
}
int main()
{
    int capacity = 10;
    struct queue *queue = createQueue(capacity);

    // Enqueue elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    // Dequeue elements
    dequeue(queue);
    dequeue(queue);

    // Enqueue more elements
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Dequeue more elements
    dequeue(queue);
    return 0;
}