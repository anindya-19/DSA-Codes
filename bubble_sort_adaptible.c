#include<stdio.h>

void printArr(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
} 

void bubbleSortAdaptive(int *arr,int n)
{
    int i,temp,j;
    int isSorted = 0;
    for(i=0;i<n-1;i++) // for the passing, n-1 because if we arrange the n-1 elements then one will get placed eventually
    {
        printf("working on pass number %d \n",i+1);

        isSorted = 1;
        for(j=0;j<n-i-1;j++) // as with each pass, we decrease the comparison by one 
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1]; // simple swapping 
                arr[j+1] = temp;
                isSorted = 0; // 0 means false, hence as swapping was done, it wont return now.
            }
        }
        if(isSorted) // that means in the first pass, the swapping was not done, hence already sorted!
            return;
    }
}

void bubbleSort(int *arr,int n)
{
    int i,temp,j;
    for(i=0;i<n-1;i++) // for the passing, n-1 because if we arrange the n-1 elements then one will get placed eventually
    {
        printf("working on pass number %d \n",i+1);
        for(j=0;j<n-i-1;j++) // as with each pass, we decrease the comparison by one 
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1]; // simple swapping 
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    // int arr[] = {7,11,9,2,17,4};
    // int arr[] = {1,2,3,4,5,6};
    int arr[] = {1,2,5,6,12,54,625,7,23,9,87};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("The array before sorting : \n");
    printArr(arr,size);

    bubbleSortAdaptive(arr,size);
    printf("The array after sorting \n");
    printArr(arr,size);

    return 0;

}