#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//partition function 
int partition(int arr[] , int start  , int end )
{
    int pivot , temp , index;
    pivot = arr[end];
    index = start -1;
    for (int i = start; i < end; i++)//i will raverse the array provided 
    {
    if(arr[i] < pivot )
      index++;
    }
    arr[index] = pivot;
    return index;
}

void quick_sort(int arr[] , int start , int end)
{
    if(start < end){
int pivot_index = partition(arr , start ,end);
quick_sort(arr , start ,pivot_index -1);
quick_sort(arr , pivot_index+1 , end);
}
}

void display(int arr[] , int n)
{
    printf("The array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d",arr[i]);
    }
    
}
int main()
{
    int arr[] = {4, 3 ,2,1 ,5};
    int n =sizeof(arr)/sizeof(arr[0]);
    printf("Before sorting \n");
    display(arr , n);
     quick_sort(arr , 0 ,n-1);
     printf("After sorting : \n");
    display(arr , n);

    return 0;
}