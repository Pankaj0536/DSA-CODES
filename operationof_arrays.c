#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// insertion of array
void insertion(int *a, int *size, int total_size);
// deletion in array
void deletion(int *a, int *size);
// linear search
void lsearch(int *arr, int *size);
// Binary search
int binary_search(int *arr, int *size, int element);
// control panel
void controlpanel(int *arr, int *size, int total_size);

void display(int *a, int *size);
int main()
{

    int arr[100] = {12, 23, 56, 32};
    int size = 4;
    display(arr, &size);
    controlpanel(arr, &size, 100);
    return 0;
}
void controlpanel(int *arr, int *size, int total_size)
{
    int input, success, element, set;
    printf("\n");
   do 
    {
        do
        {
            printf("Enter: \n1 -> Insertion\n2 -> Deletion\n3 -> Searching\nYour choice: ");
            success = scanf("%d", &input);

            // Clear the input buffer if non-integer is entered
            if (success != 1)
            {
                while (getchar() != '\n')
                    ; // flush input buffer
                printf("Invalid input. Please enter a number (1, 2, or 3).\n");
                continue;
            }

            if (input < 1 || input > 3)
            {
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
            }
        } while (input < 1 || input > 3);
        printf("You selected option %d.\n", input);
        switch (input)
        {
        case 1:
            insertion(arr, size, 100);
            display(arr, size);
            break;
        case 2:

            deletion(arr, size);
            display(arr, size);

            break;
        case 3:
            printf("Which searching you will prefer \n");
            do
            {
                printf("Enter: \n1 -> Binary Search\n2 -> Linear search\nYour choice: ");
                success = scanf("%d", &input);

                // Clear the input buffer if non-integer is entered
                if (success != 1)
                {
                    while (getchar() != '\n')
                        ; // flush input buffer
                    printf("Invalid input. Please enter a number (1 or 2).\n");
                    continue;
                }

                if (input < 1 || input > 2)
                {
                    printf("Invalid choice. Please enter 1, 2, or 3.\n");
                }
            } while (input < 1 || input > 2);
            printf("You selected option %d.\n", input);
            display(arr, size);
            if (input == 1)
            {
                printf("Enter the element which you want to search: \n");
                scanf(" %d", &element);
                if (binary_search(arr, size, element) == -1)
                {
                    printf("Element %d not found\n", element);
                }
                else
                {
                    printf("Element %d is found at index number %d \n", element, binary_search(arr, size, element));
                }
            }
            else
                lsearch(arr, size);
            break;
        }
        printf("Enter: \n1-> stop\n2->Go\n");
        scanf(" %d",&set);
    }while (set != 0);
}
// insertion defination..
void insertion(int *a, int *size, int total_size)
{
    int element, index, success;
    if (*size >= total_size)
    {
        printf("The array is full cannot insert element.\n");
    }
    else
    {
        printf("Enter the element which you want to insert :\n");
        scanf(" %d", &element);

        do
        {
            printf("Enter the index number where you want to insert : \n");
            success = scanf("%d", &index);

            // Clear the input buffer if non-integer is entered
            if (success != 1)
            {
                while (getchar() != '\n')
                    ; // flush input buffer
                printf("Invalid input. Please enter a valid number (0 to %d).\n", *size - 1);
                continue;
            }
            if (index < 0 || index > *size - 1)
            {
                printf("Please enter a valid number (0 to %d).\n", *size - 1);
            }
        } while (index < 0 || index > 99);

        for (int i = *size - 1; i >= index; i--)
        {
            a[i + 1] = a[i];
        }
        a[index] = element;
        printf("The element %d is inserted succesfully \n", element);
        (*size)++;
    }
}
// deletion defination..
void deletion(int *a, int *size)
{
    int index, element;
    if (*size <= 0)
    {
        printf("The array is empty cannot delete any element \n");
    }
    else
    {
        printf("Enter the element which you want to delete : \n");
        scanf(" %d", &element);
        index = binary_search(a, size, element);
        if (index == -1)
        {
            printf("The element %d is not exist in the array.\n", element);
            return;
        }
        for (int i = index; i < *size; i++)
        {
            a[i] = a[i + 1];
        }
        printf("The element %d is deleted succesfully.\n", element);
        (*size)--;
    }
}
// liner searching defination..
void lsearch(int *arr, int *size)
{
    int element, index = -1;
    printf("Enter the element which you want to search : ");
    scanf(" %d", &element);
    for (int i = 0; i < *size; i++)
    {
        if (arr[i] == element)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("The element %d is not found \n", element);
    }
    else
    {
        printf("The element %d is found at index number %d\n", element, index);
    }
}
// binary search defination..
int binary_search(int *arr, int *size, int element)
{
    int start = 0, end = *size - 1, mid, set = -1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == element)
        {
            set = mid;
            break;
        }
        else if (arr[mid] < element)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return set;
}
// display defination..

void display(int *a, int *size)
{
    printf("The array is : ");
    for (int i = 0; i < *size; i++)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
}