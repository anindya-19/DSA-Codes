#include <stdio.h>
#include <stdlib.h>
void divide(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
void printArr(int arr[], int n);

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int low, int mid, int high)
{
    int *temp = (int *)malloc( (high-low+1) * sizeof(int));
    int k, i, j;
    k = low;
    i = low;
    j = mid + 1;
    
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k-low] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k-low] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k-low] = arr[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        temp[k-low] = arr[j];
        k++;
        j++;
    }

    for (int m = low; m <= high; m++)
    {
        arr[m] = temp[m-low];
    }
    free(temp);
}

void divide(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        divide(arr, low, mid);
        divide(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {32, 94, 14, 10, 56, 74, 61, 59};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The array before sorting \n");
    printArr(arr, n);

    printf("The array after sorting: \n");
    divide(arr, 0, n - 1);
    printArr(arr, n);
}
