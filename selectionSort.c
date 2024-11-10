#include <stdio.h>

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int n)
{
    int min, temp, i, j;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++) // as we have to check after the i position of array
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min]; // swap
        arr[min] = temp;
    }
}

int main()
{
    // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13

    int arr[] = {3, 5, 2, 13, 12};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("The array before sorting :\n");
    printArr(arr, size);

    printf("The array after sorting :\n");
    selectionSort(arr, size);
    printArr(arr, size);
    return 0;
}