#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// global variable size
int size;
// linked list traversal
void linkedlist_traversal(struct node *head);

// deletion from first

struct node *delete_first_node(struct node *head)
{
    struct node *p = head;
    head = head->next;
    free(p);
    return head;
}

struct node *delete_at_index(struct node *head, int index)
{
    struct node *p = head;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }
    struct node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct node *delete_by_node(struct node *Node, struct node *head)
{
    struct node *p;
    p = head;

    while (p->next != Node)
    {
        p = p->next;
    }
    p->next = Node->next;
    free(Node);
    return head;
}

struct node *delete_last_node(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
int main()
{
    int success, input, index;
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
    third->next = fourth;
    fourth->data = 78;
    fourth->next = NULL;
    size = 4;
    printf("**Welcome to deletion**\n");
    do
    {
        printf("Enter :\n1->delete from first\n2->delete by giving index\n3->delete by giving node \n4->delete the last node\nyour input:\n");
        success = scanf("%d", &input);
        if (success != 1)
        {
            while (getchar() != '\n')
                ; // flush input buffer
            printf("Invalid input. Please enter a valid number.\n");
            continue;
        }
        if (input > 4 || index < 1)
        {
            printf("Invalid Input!! linkedlist out of bound.\n");
        }
    } while (input < 1 || input > 4);
    switch (input)
    {
    case 1:
        printf("The linkedlist before deletion : \n");
        linkedlist_traversal(head);
        head = delete_first_node(head);
        printf("\nThe linkedlist after deletion : \n");
        linkedlist_traversal(head);
        break;
    case 2:
        do
        {
            printf("Enter the index number of node which you want to delete:\n");
            success = scanf("%d", &index);
            if (success != 1)
            {
                while (getchar() != '\n')
                    ; // flush input buffer
                printf("Invalid input. Please enter a valid number.\n");
                continue;
            }
            if (index > size - 1 || index < 0)
            {
                printf("Invalid Input!! linkedlist out of bound.\n");
            }
        } while (index < 0 || index > size - 1);
        printf("The linkedlist before deletion : \n");
        linkedlist_traversal(head);
        head = delete_at_index(head, index);
        printf("\nThe linkedlist after deletion : \n");
        linkedlist_traversal(head);
        break;
    case 3:
        printf("The linkedlist before deletion : \n");
        linkedlist_traversal(head);
        head = delete_by_node(second, head);
        printf("\nThe linkedlist after deletion : \n");
        linkedlist_traversal(head);
        break;

    case 4:
        printf("The linkedlist before deletion : \n");
        linkedlist_traversal(head);
        head = delete_last_node(head);
        printf("\nThe linkedlist after deletion : \n");
        linkedlist_traversal(head);
        break;

    }

    return 0;
}

// linkedlist traversal function defination..
void linkedlist_traversal(struct node *head)
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}