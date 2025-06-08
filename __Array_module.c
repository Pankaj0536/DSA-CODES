#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// structure or set of values
typedef struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
} myarray;

// to create an array
int createArray(myarray *a);

// to set value in array
void Setval(myarray *array);

// to dispaly the array
void display(myarray *arr);

// further operation function

void further_operations(myarray *array);

// which operations
void operation(int choice, myarray *a);

// insertion in array
void insertion(myarray *arr);

// deletion of element in array
void deletion(myarray *arr);

// serching the element in array
void Search_element(myarray *arr);

// sorting an array
void Sort_Array(myarray *arr);

int main()
{
    myarray arr;
    if (createArray(&arr))
    {
        printf("memory Allocated Succesfully.\n");
        Setval(&arr);
        display(&arr);
    }
    else
    {
        printf("Exiting program due to memory allocation failure\n");
        return -1;
    }
    further_operations(&arr);
    free(arr.ptr);
    return 0;
}
int createArray(myarray *a)
{
    printf("Enter the total size of the array : ");
    scanf("%d", &a->total_size);
    printf("Enter the used size of the array : ");
    scanf("%d", &a->used_size);
    a->ptr = (int *)malloc(a->total_size * sizeof(int));
    if (a->ptr == NULL)
    {
        printf("oops!! Memory allocation is failed.\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

void Setval(myarray *array)
{
    for (int i = 0; i < array->used_size; i++)
    {
        printf("Enter the element at position %d : \n", i + 1);
        scanf("%d", &(array->ptr)[i]);
    }
}

void display(myarray *arr)
{
    printf("The array is : ");
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("%d ", (arr->ptr)[i]);
    }
}

void further_operations(myarray *array)
{
    char input[100];
    int choice;
    printf("Do you like to do some other operations with your array (Yes/No): ");
    while (1)
    {
      input[strcspn(input, "\n")] = '\0'; // reads the whole line including spaces
        for (int i = 0; input[i] != '\0'; i++)
        {
            input[i] = toupper(input[i]); // convert each character to uppercase
        }
        if (strcmp(input, "YES") == 0 || strcmp(input, "NO") == 0)
        {
            break;
        }
        else
        {
            printf("!! Envalid input \n Enter input : ");
        }
    }
    if (strcmp(input, "YES") == 0)
    {
        printf("Enter : \n1->INSERION\n2->DELETION\n3->SORTING\n4->SEARCHNG\n");
        scanf("%d", &choice);
        operation(choice, array);
    }
}

void operation(int choice, myarray *a)
{
    switch (choice)
    {
    case 1:
        insertion(a);
        break;

    case 2:
        deletion(a);

        break;

    case 3:
        Sort_Array(a);
        break;

    case 4:
        Search_element(a);
        break;

    default:
        printf("!!Invalid choice \n");
        break;
    }
}

void insertion(myarray *arr)
{
    int index, element;
    printf("Enter the index number where you want to insert the element : ");
    scanf("%d", &index);
    printf("Enter the element : ");
    scanf("%d", &element);
    arr->used_size++;
    for (int i = 0; i < arr->used_size; i++)
    {
        if (i == index)
        {
            arr->ptr[i] == element;
        }
    }
    display(&arr);
}