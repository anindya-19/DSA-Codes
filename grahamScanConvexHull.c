#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

typedef struct point
{
    int x, y;
} Point;
Point stack[MAX];
int top = -1;
// A global point needed for  sorting points with reference
// to  the first point Used in compare function of qsort()
Point p0;

void swap(Point *a, Point *b)
{
    Point temp = *a;
    *a = *b;
    *b = temp;
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;             // collinear
    return (val > 0) ? 1 : 2; // 1: clockwise, 2: counter-clockwise
}

int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y); //using pythagorean theorem to find the distance between two points
}

int compare(const void *a, const void *b)
{
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;

    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

void push(Point p)
{
    stack[++top] = p;
}

Point nextToTop()
{
    return stack[top - 1];
}

Point pop()
{
    return stack[top--];
}

void convexHull(Point points[], int n)
{
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        // Pick the bottom-most or choose the left
        // most point in case of tie
        int y = points[i].y;
        if ((y < ymin) || (y == ymin && points[i].x < points[min].x))
        {
            ymin = points[i].y;
            min = i;
        }
    }

    swap(&points[0], &points[min]);
    p0 = points[0];

    qsort(&points[1], n - 1, sizeof(Point), compare);

    // Create an empty stack and push first three points
    // to it.
    push(points[0]);
    push(points[1]);
    push(points[2]);

    for (int i = 3; i < n; i++)
    {
        while (orientation(nextToTop(), stack[top], points[i]) != 2)
            pop();
        push(points[i]);
    }

    printf("Convex Hull points:\n");
    for (int i = 0; i <= top; i++)
        printf("(%d, %d)\n", stack[i].x, stack[i].y);
}
int main()
{
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};

    int n = sizeof(points) / sizeof(points[0]);

    convexHull(points, n);
}