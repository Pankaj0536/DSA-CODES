#include <stdio.h>

// Display function 
void display(int arr[], int n);

// Swap function 
void swap(int *first, int *second);

// Partition Function 
int partition(int arr[], int start, int end);

int main()
{
    int arr[] = {10, 4, 6, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Before Sorting :\n");
    display(arr, n);

    printf("\nAfter Sorting :\n");
    quicksort(arr, 0, n - 1);
    display(arr, n);

    return 0;
}

//display function defination 
void display(int arr[], int n)
{
    printf("The array is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

//Swap function defination
void swap(int *first, int *second)
{
    int temp;
    temp = *first;
    *first = *second;
    *second = temp;
}

//Partition function defination
int partition(int arr[], int start, int end)
{
    int index = start - 1;
    int temp, pivot = arr[end];
    for (int j = start; j < end; j++)
    {
        if (arr[j] <= pivot)
        {
            index++;
            // swap
            swap(&arr[index], &arr[j]);
        }
    }
    index++;
    swap(&arr[index], &arr[end]);

    return index;
}

//Quicksort function dfination
void quicksort(int arr[], int st, int end)
{
    int pi; // pivotindex
    if (st < end)
    {
        pi = partition(arr, st, end);
        quicksort(arr, st, pi - 1);
        quicksort(arr, pi + 1, end);
    }
    return;
}
