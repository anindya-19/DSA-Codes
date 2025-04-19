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
void convexHull(Point points[], int n)
{
    int ymin = points[0].y, min = 0;
}
int main()
{
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};

    int n = sizeof(points) / sizeof(points[0]);

    printf("%d", points[0].y);
}