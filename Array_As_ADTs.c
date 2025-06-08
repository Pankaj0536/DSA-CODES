#include <stdio.h>
#include <stdlib.h>

struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myarray *a, int total_size, int used_size)
{
    a->total_size = total_size;
    a->used_size = used_size;
    a->ptr = (int *)malloc(total_size * sizeof(int));
}

void setval(struct myarray *array)
{
    int n;
    for (int i = 0; i < array->used_size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &n);
        (array->ptr)[i] = n;
    }
}

void show(const struct myarray *a)
{
    printf("Array elements: ");
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d ", (a->ptr)[i]);
    }
    printf("\n");
}

int main()
{
    struct myarray arr;
    createArray(&arr, 10, 4);
    setval(&arr);
    show(&arr);
    free(arr.ptr);
    return 0;
}
