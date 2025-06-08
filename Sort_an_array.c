#include <stdio.h>
#include <stdlib.h>
// bubble sort
void bubble_sort(int arr[], int size)
{
    int temp, set = 1;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] == arr[j + 1])
            {
                printf("\nAlert!! array contain same element.\n");
            }
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                set = 0;
            }
            if (set == 1)
                return;
        }
    }
}

void selection_sort(int arr[], int n)
{
    int smallestindex, temp;
    for (int i = 0; i < n - 1; i++)
    {
        smallestindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestindex])
                smallestindex = j;
        }
        temp = arr[i];
        arr[i] = arr[smallestindex];
        arr[smallestindex] = temp;
    }
}

void insertion_sort(int arr[], int n)
{
    int current, previous;
    for (int i = 1; i < n; i++)
    {
        current = arr[i];
        previous = i - 1;

        while (arr[previous] > current && previous >= 0)
        {
            arr[previous + 1] = arr[previous];
            previous--;
        }
        arr[previous + 1] = current;
    }
}

void display(int array[], int size)
{
    printf("your arrray is : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

int main()
{
    int arr[] = {8, 3, 2 ,7,1 };
    int input, success;
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("**welcome to sorting**\n");
    display(arr , size);
    do
    {
        printf("\nEnter : \n1->Bubble sort \n2->Selecion sort \n3->Insertion sort\nyour input:");
        success = scanf("%d", &input);
        if (success != 1)
        {
            while (getchar() != '\n')
                ; // flush input buffer
            printf("Invalid input. Please enter a valid number (0 to 3).\n");
            continue;
        }
        if (input < 0 || input > 3)
        {
            printf("Please enter a valid number (0 to 3).\n");
        }
    } while (input < 0 || input > 3);
    switch (input)
    {
    case 1:
        /* code */
        printf("before sorting :\n");
        display(arr, size);
        bubble_sort(arr, size);
        printf("After sorting:\n");
        display(arr, size);
        break;
    case 2:

        printf("before sorting :\n");
        display(arr, size);
        selection_sort(arr, size);
        printf("After sorting:\n");
        display(arr, size);
        break;
    case 3:
        printf("before sorting :\n");
        display(arr, size);
        insertion_sort(arr, size);
        printf("After sorting:\n");
        display(arr, size);
        break;
    }

    return 0;
}