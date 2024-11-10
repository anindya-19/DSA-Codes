#include <stdio.h>

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do // not working with while loop, as we will be checking the condition whether i < j at the very begining, so we will not get the opportunity to swap the elements, as we are exiting the loop before hand. Hence do while loop does the job
    {
        while (arr[i] <= pivot) // to search for elements greater than pivot for right side
        {
            i++;
        }
        while (arr[j] > pivot) // to search for elements lesser than pivot for left side
        {
            j--;
        }
        if (i < j) // the if block returs false as soon as i > j; that is start is greater than end. Hence they have crossed paths!!
        {
            temp = arr[i]; // swap start and end as soon as we find the required condition
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[low];   // here arr[low] means pivot
    arr[low] = arr[j]; // if start greater than end, the we exchange the pivot with end!!
    arr[j] = temp;
    return j;
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);  // sort left subarray
        quickSort(arr, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    int arr[] = {2,6,7,5,1,7,9,15,10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("array before sorting \n");
    printArr(arr, size);

    quickSort(arr, 0, size - 1);
    printf("array after sorting \n");
    printArr(arr, size);
}
