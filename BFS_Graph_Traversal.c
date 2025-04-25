#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queue *q)
{
    if (q->r == q->f)
        return 1;
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("The queue is full ");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("The queue is empty ");
        return -1;
    }
    else
    {
        q->f++;
        return q->arr[q->f];
    }
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));

    q->f = -1;
    q->r = -1;
    q->size = 400;
    q->arr = (int *)malloc(sizeof(int));

    int node;
    int i = 0;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0}, // 0
        {1, 0, 1, 0, 0, 0, 0}, // 1
        {1, 1, 0, 1, 1, 0, 0}, // 2
        {1, 0, 1, 0, 1, 0, 0}, // 3
        {0, 0, 1, 1, 0, 1, 1}, // 4
        {0, 0, 0, 0, 1, 0, 0}, // 5
        {0, 0, 0, 0, 1, 0, 0}, // 6
    };// 0  1  2  3  4  5  6

    printf("%d", i);
    visited[i] = 1;
    enqueue(q, i);
    while (!isEmpty(q))
    {
        node = dequeue(q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }
}