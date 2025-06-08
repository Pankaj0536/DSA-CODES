#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
//linked list traversal
void linkedlist_traversal(struct node *head);


int main()
{
    struct node *head, *second, *third, *fourth;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    head->data = 12;
    head->next = second;
    second->data = 34;
    second->next = third;
    third->data = 22;
    third->next= fourth;
    fourth->data = 78;
    fourth->next = NULL;
    linkedlist_traversal(head);

    return 0;
}

//linkedlist traversal function defination..
    void linkedlist_traversal(struct node *head)
    {
        struct node * ptr;
        ptr = head;
        while (ptr != NULL)
        {
       printf("%d ",ptr->data);
       ptr = ptr->next;
        }
    }