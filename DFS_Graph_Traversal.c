#include <stdio.h>
#include <stdlib.h>

int A[7][7] = {
    {0, 1, 1, 1, 0, 0, 0}, // 0
    {1, 0, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 0}, // 2
    {1, 0, 1, 0, 1, 0, 0}, // 3
    {0, 0, 1, 1, 0, 1, 1}, // 4
    {0, 0, 0, 0, 1, 0, 0}, // 5
    {0, 0, 0, 0, 1, 0, 0}, // 6
};// 0  1  2  3  4  5  6
int visited[7] = {0, 0, 0, 0, 0, 0, 0};

void DFS(int i)
{
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (A[i][j] == 1 && !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    DFS(4);
    return 0;
    // here we are using the built in stack of c compiler
}