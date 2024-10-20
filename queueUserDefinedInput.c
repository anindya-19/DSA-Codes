// Queue using array!
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct queue
{
    int front;
    int rear;
    int arr[MAX];
};
int isFull(struct queue *q)
{
    if (q->rear == MAX - 1)
        return 1;
    return 0;
}
int isEmpty(struct queue *q)
{
    if (q->front == -1)
        return 1;
    return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("The queue is full!");
        return;
    }
    if (q->front == -1)
        q->front = 0; // increment the value of front by 1 as we are inserting the first element of the queue
    q->rear++;
    q->arr[q->rear] = val;
    printf("%d was successfully enqueued! \n", val);
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue is already empty!");
        return -1;
    }
    int value = q->arr[q->front];
    q->front++;
    
    if (q->front > q->rear) // means all the elements are dequeued, hence reset the queue
        q->front = q->rear = -1;

    return value; // dequeued value
}

void display(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue is already empty!");
        return;
    }
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d \n", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    int c = 0, n, ch;
    printf("Enter the elements that you want to enqueue :\n");
    while (c != MAX)
    {
        printf("Enter the element :");
        scanf("%d", &n);
        enqueue(q, n);

        printf("Press 1 to break");
        scanf("%d", &ch);
        if (ch == 1)
            break;
        c++;
    }
    printf("The current queue:");
    display(q);

    printf("_____________Now Dequeuing elements______________ \n");
    while(c >= 0)
    {
        printf("%d was dequeued \n", dequeue(q));
        printf("Press 1 to stop dequeue process \n");
        scanf("%d", &ch);
        if (ch == 1)
            break;
    }
    return 0;
}
