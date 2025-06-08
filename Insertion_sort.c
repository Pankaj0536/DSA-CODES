#include <stdio.h>

void display(int arr[] , int n)
{
    printf("The array is : \n");
    for (int i = 0; i < n; i++)
    {
       printf("%d ",arr[i]);
    }  
}

int main()
{
    int arr[] = {4, 2, 6, 1};
    int prev, curr;
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("\nBefore sorting : \n");
    display(arr , n);
    for (int i = 1; i < n; i++)
    {
        prev = i - 1;
        curr = arr[i];
        while (arr[prev] > curr && prev >= 0)
        {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
    printf("\nAfter sorting :\n");
    display(arr , n);

    return 0;
}