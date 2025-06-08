#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void display(int arr[] , int n)
{
    printf("The array is : \n");
    for (int  i = 0; i < n; i++)
    {
       printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {5 ,4, 3 ,2 ,1 };
    int temp,smallest_index;
    int n  = sizeof(arr)/sizeof(arr[0]);
    printf("Before sorting :\n");
    display(arr , n);
    for(int i = 0 ; i<n-1 ; i++)
    {
        smallest_index = i;
for (int j= i+1; j< n; j++)
{
  if(arr[j] < arr[smallest_index])
  {
      smallest_index = j;
    }
    temp = arr[i];
    arr[i] = arr[smallest_index];
    arr[smallest_index] = temp;
}

}
printf("After sorting\n");
display(arr , n);

   return 0;
}