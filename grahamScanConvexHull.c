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
}
int main()
{
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};

    int n = sizeof(points) / sizeof(points[0]);

    printf("%d", points[0].y);
}